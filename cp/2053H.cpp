#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Find all groups of equal adjacent elements
    vector<pair<int, int>> groups;  // {start_idx, length}
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) {
            int start = i;
            while (i + 1 < n && a[i] == a[i + 1]) {
                i++;
            }
            groups.push_back({start, i - start + 1});
        }
    }
    
    ll max_sum = 0;
    int min_ops = 0;
    
    if (groups.empty()) {
        // If no equal adjacent elements, sum the array
        max_sum = accumulate(a.begin(), a.end(), 0LL);
        min_ops = 0;
    } else {
        // For each group, replace with maximum possible values
        // that maintain inequality with adjacent elements
        vector<int> result = a;
        
        for (auto [start, len] : groups) {
            min_ops += (len + 1) / 2;  // Minimum operations needed for this group
            
            // For each position in the group, try to put the largest possible value
            for (int i = start; i < start + len; i++) {
                // Get values of adjacent elements (outside the group)
                int prev_val = (i > 0) ? result[i - 1] : 0;
                int next_val = (i < n - 1) ? result[i + 1] : 0;
                
                // If at even position relative to group start, try w
                // If at odd position, try w-1 to maintain inequality
                if ((i - start) % 2 == 0) {
                    result[i] = w;
                } else {
                    result[i] = w - 1;
                }
                
                // Ensure inequality with adjacent elements
                if (i > 0 && result[i] == result[i - 1]) {
                    result[i]--;
                }
                if (i < n - 1 && result[i] == result[i + 1]) {
                    result[i]--;
                }
            }
        }
        
        max_sum = accumulate(result.begin(), result.end(), 0LL);
    }
    
    cout << max_sum << " " << min_ops << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}