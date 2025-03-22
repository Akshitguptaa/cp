#include <bits/stdc++.h>
using namespace std;

long long countSubstrings(int n, string a, string b, int k) {
    // Function to count valid substring pairs in current state
    auto countValidPairs = [&](string s) {
        long long cnt = 0;
        for(int l = 0; l < n; l++) {
            bool valid = true;
            for(int r = l; r < n && valid; r++) {
                if(s[r] != b[r]) valid = false;
                if(valid) cnt++;
            }
        }
        return cnt;
    };
    
    // If k = 0, we can't modify anything
    if(k == 0) return countValidPairs(a);
    
    // For each position, try changing to match b or keep original
    string curr = a;
    set<char> used;
    vector<int> can_change;
    
    // Find positions where a differs from b
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            can_change.push_back(i);
        }
    }
    
    long long ans = countValidPairs(a);  // Initial answer without changes
    
    // Try all possible combinations of changes
    int m = can_change.size();
    for(int mask = 0; mask < (1 << m); mask++) {
        string temp = a;
        set<char> q;
        
        // Apply changes according to current mask
        for(int j = 0; j < m; j++) {
            if(mask & (1 << j)) {
                int pos = can_change[j];
                q.insert(a[pos]);
                temp[pos] = b[pos];
            }
        }
        
        // If number of changes is within limit k
        if(q.size() <= k) {
            ans = max(ans, countValidPairs(temp));
        }
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;
        
        cout << countSubstrings(n, a, b, k) << "\n";
    }
    
    return 0;
}