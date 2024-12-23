#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    // Input the array a[i][j]
    ll a[511][511];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Brute-force approach:
    ll min_cost = LLONG_MAX;
    
    // Try all possible combinations of shifts for all rows
    for (int shift = 0; shift < m; shift++) {
        // For each row, check each shift and calculate the corresponding cost
        ll cost = 0;
        for (int i = 1; i <= n; i++) {
            // For the i-th row, check the minimum cost of shifting by any value
            ll row_min_cost = LLONG_MAX;
            for (int j = 0; j < m; j++) {
                row_min_cost = min(row_min_cost, a[i][(j + shift) % m] + k * 1LL * shift);
            }
            cost += row_min_cost;
        }
        min_cost = min(min_cost, cost);
    }
    
    cout << min_cost << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}
