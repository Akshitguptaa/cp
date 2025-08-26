#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    vector<vector<long long>> dp(6, vector<long long>(6, -1LL));

    dp[0][0] = 0LL;

    for (int i = 0; i < n; ++i) {
        vector<vector<long long>> new_dp(6, vector<long long>(6, -1LL));
        
        int current_type = a[i];
        long long current_happiness = b[i];

        for (int t1 = 0; t1 <= 5; ++t1) {
            for (int t2 = 0; t2 <= 5; ++t2) {
                if (dp[t1][t2] == -1LL) {
                    continue;
                }

                new_dp[t1][t2] = max(new_dp[t1][t2], dp[t1][t2]);

                long long happiness_to_add = current_happiness;
                
                if (t1 != 0 && (current_type == t1 || current_type == t2)) {
                    happiness_to_add *= 2;
                }
                
                int new_t1 = current_type;
                int new_t2 = t1;
                
                new_dp[new_t1][new_t2] = max(new_dp[new_t1][new_t2], dp[t1][t2] + happiness_to_add);
            }
        }
        dp = move(new_dp);
    }

    long long max_happiness = 0LL;
    for (int t1 = 0; t1 <= 5; ++t1) {
        for (int t2 = 0; t2 <= 5; ++t2) {
            max_happiness = max(max_happiness, dp[t1][t2]);
        }
    }

    cout << max_happiness << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}