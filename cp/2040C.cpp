#include <bits/stdc++.h>
using namespace std;

// Precomputing factorials up to a maximum n (20 in this case to handle up to 20!)
long long fact[21];  // Fact array to store factorials from 0! to 20!

// Function to compute factorials from 0! to n!
void precompute_factorials(int n) {
    fact[0] = 1;  // 0! is 1 by definition
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;  // Compute factorial: fact[i] = i!
    }
}

// Function to compute the k-th permutation of size n
vector<int> get_kth_permutation(int n, long long k) {
    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 1);  // Fill with numbers [1, 2, ..., n]
    
    vector<int> result;
    k--;  // Convert k to zero-indexed
    
    // Generate the k-th permutation using factorial number system
    for (int i = n - 1; i >= 0; i--) {
        long long block_size = fact[i];  // Block size for the remaining numbers
        int idx = k / block_size;  // Determine which number should be placed at the current position
        k %= block_size;  // Update k to reflect the remaining block after selecting the current number
        
        result.push_back(perm[idx]);  // Add the selected number to the result
        perm.erase(perm.begin() + idx);  // Remove the selected number from the list
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // Precompute factorials up to 20 (this should be enough for this problem)
    precompute_factorials(20);  // We are concerned with permutations up to n = 20
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        
        // Check if the requested k-th permutation exists
        long long total_permutations = fact[n];
        
        // If k is larger than the number of permutations, output -1
        if (k > total_permutations) {
            cout << -1 << '\n';
        } else {
            // Generate and print the k-th permutation
            vector<int> result = get_kth_permutation(n, k);
            for (int num : result) {
                cout << num << ' ';
            }
            cout << '\n';
        }
    }
    
    return 0;
}
