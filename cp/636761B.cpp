#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;

// Define a type for unsigned 64-bit integers for large numbers.
using ull = unsigned long long;

// Modulo constant
const long long MOD = 998244353;

// A map to store frequencies of numbers.
using FreqMap = map<ull, int>;

// Forward declaration for the recursive pair counting function.
long long count_valid_pairs(const FreqMap& A, const FreqMap& B, ull x, int p);

// Main recursive function to solve the problem.
long long solve(const FreqMap& counts, ull x, int p) {
    // Base case: if the set is empty or we've processed all bits.
    if (counts.empty() || p < 0) {
        long long total_count = 1;
        for (auto const& [val, freq] : counts) {
            total_count = (total_count * (freq + 1)) % MOD;
        }
        return (total_count - 1 + MOD) % MOD;
    }

    ull mask = 1ULL << p;
    FreqMap S0, S1;

    // Partition the current set based on the p-th bit.
    for (auto const& [val, freq] : counts) {
        if (val & mask) {
            S1[val] = freq;
        } else {
            S0[val] = freq;
        }
    }

    // Case 1: p-th bit of x is 0.
    if (!((x >> p) & 1)) {
        long long ways0 = solve(S0, x, p - 1);
        long long ways1 = solve(S1, x, p - 1);
        // Combine results: (ways0 + 1) * (ways1 + 1) - 1
        long long ans = (ways0 + ways1) % MOD;
        ans = (ans + (ways0 * ways1) % MOD) % MOD;
        return ans;
    } 
    // Case 2: p-th bit of x is 1.
    else {
        // Valid subsequences can have at most one element from S0 and one from S1.
        // Ways for subsequences of size 1 from S0.
        long long singletons0 = 0;
        for (auto const& [val, freq] : S0) {
            singletons0 = (singletons0 + freq) % MOD;
        }
        // Ways for subsequences of size 1 from S1.
        long long singletons1 = 0;
        for (auto const& [val, freq] : S1) {
            singletons1 = (singletons1 + freq) % MOD;
        }
        
        // Count pairs (u, v) from S0 x S1 that satisfy the condition.
        long long pair_ways = count_valid_pairs(S0, S1, x, p - 1);
        
        long long ans = (singletons0 + singletons1) % MOD;
        ans = (ans + pair_ways) % MOD;
        return ans;
    }
}

// Recursive function to count valid pairs between two sets.
long long count_valid_pairs(const FreqMap& A, const FreqMap& B, ull x, int p) {
    if (A.empty() || B.empty() || p < 0) {
        long long size_A = 0, size_B = 0;
        for(auto const& [v, f] : A) size_A = (size_A + f) % MOD;
        for(auto const& [v, f] : B) size_B = (size_B + f) % MOD;
        return (size_A * size_B) % MOD;
    }
    
    ull mask = 1ULL << p;
    FreqMap A0, A1, B0, B1;
    long long size_A0=0, size_A1=0, size_B0=0, size_B1=0;

    for (auto const& [val, freq] : A) {
        if (val & mask) { A1[val] = freq; size_A1 = (size_A1 + freq) % MOD; }
        else { A0[val] = freq; size_A0 = (size_A0 + freq) % MOD; }
    }
    for (auto const& [val, freq] : B) {
        if (val & mask) { B1[val] = freq; size_B1 = (size_B1 + freq) % MOD; }
        else { B0[val] = freq; size_B0 = (size_B0 + freq) % MOD; }
    }

    long long ans = 0;
    // Case 1: p-th bit of x is 0.
    if (!((x >> p) & 1)) {
        ans = (ans + count_valid_pairs(A0, B0, x, p - 1)) % MOD;
        ans = (ans + count_valid_pairs(A1, B1, x, p - 1)) % MOD;
        // Pairs from A0 x B1 and A1 x B0 always satisfy the condition at this bit.
        ans = (ans + (size_A0 * size_B1) % MOD) % MOD;
        ans = (ans + (size_A1 * size_B0) % MOD) % MOD;
    } 
    // Case 2: p-th bit of x is 1.
    else {
        // Only cross-pairs where XOR has p-th bit 1 are candidates.
        ans = (ans + count_valid_pairs(A0, B1, x, p - 1)) % MOD;
        ans = (ans + count_valid_pairs(A1, B0, x, p - 1)) % MOD;
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ull x;
    cin >> n >> x;

    FreqMap counts;
    ull max_val = x;
    for (int i = 0; i < n; ++i) {
        ull val;
        cin >> val;
        counts[val]++;
        if (val > max_val) {
            max_val = val;
        }
    }

    if (x == 0) {
        long long total_count = 1;
        for (auto const& [val, freq] : counts) {
            total_count = (total_count * (freq + 1)) % MOD;
        }
        cout << (total_count - 1 + MOD) % MOD << endl;
        return 0;
    }
    
    int p = 0;
    if (max_val > 0) {
        p = 63 - __builtin_clzll(max_val);
    }

    cout << solve(counts, x, p) << endl;

    return 0;
}