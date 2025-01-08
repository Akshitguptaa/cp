#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
    vector<vector<pair<int, ll>>> adj;
    int n;
    
    // Returns true if there exists a path from src to dest with all edges <= mid
    // and exactly k edges >= val
    bool check(int src, int dest, ll mid, int k, ll val) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        dp[src][0] = 0;
        queue<pair<int, int>> q;
        q.push({src, 0});
        
        while (!q.empty()) {
            auto [v, count] = q.front();
            q.pop();
            
            for (auto [u, w] : adj[v]) {
                int new_count = count + (w >= val);
                if (new_count <= k && w <= mid) {
                    if (dp[u][new_count] == -1) {
                        dp[u][new_count] = 1;
                        q.push({u, new_count});
                    }
                }
            }
        }
        
        // Check if we can reach dest with exactly k edges >= val
        return dp[dest][k] != -1;
    }
    
    ll solve_query(int src, int dest, int k) {
        ll left = 0, right = 1e9 + 1;
        ll ans = -1;
        
        while (left <= right) {
            ll mid = left + (right - left) / 2;
            bool found = false;
            
            // Try all possible values for the k-th maximum
            for (ll val = 0; val <= mid; val++) {
                if (check(src, dest, mid, k, val)) {
                    found = true;
                    break;
                }
            }
            
            if (found) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
    
public:
    void solve() {
        int t;
        cin >> t;
        
        while (t--) {
            int m, q;
            cin >> n >> m >> q;
            
            // Initialize adjacency list
            adj.clear();
            adj.resize(n + 1);
            
            // Read edges
            for (int i = 0; i < m; i++) {
                int v, u;
                ll w;
                cin >> v >> u >> w;
                adj[v].push_back({u, w});
                adj[u].push_back({v, w});
            }
            
            // Process queries
            while (q--) {
                int a, b, k;
                cin >> a >> b >> k;
                cout << solve_query(a, b, k) << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solution solution;
    solution.solve();
    
    return 0;
}