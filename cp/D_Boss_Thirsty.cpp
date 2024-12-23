#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long maxProfit(int n, int m, const vector<vector<long long>>& A) {
    // dp[i] stores the maximum profit achievable up to day i
    vector<long long> dp(m + 1, LLONG_MIN);
    vector<long long> new_dp(m + 1, LLONG_MIN);

    // Day 1: Can sell any subarray
    for (int start = 1; start <= m; ++start) {
        long long current_sum = 0;
        for (int end = start; end <= m; ++end) {
            current_sum += A[0][end - 1]; // Calculate profit for the current subarray
            dp[end] = max(dp[end], current_sum); // Store maximum profit for subarray [start, end]
        }
    }

    // Process subsequent days
    for (int day = 1; day < n; ++day) {
        fill(new_dp.begin(), new_dp.end(), LLONG_MIN); // Reset new_dp for the current day

        // Calculate profit for the current day with all subarrays
        for (int start = 1; start <= m; ++start) {
            long long current_sum = 0;
            for (int end = start; end <= m; ++end) {
                current_sum += A[day][end - 1]; // Profit for the current subarray

                // Check against previous day's dp to satisfy constraints
                for (int k = 1; k <= m; ++k) {
                    if (dp[k] != LLONG_MIN) {
                        // Ensure at least one drink is common (overlap)
                        if (k >= start && k <= end) {
                            // Ensure at least one drink is new (not overlapping)
                            if (start <= k - 1 || end >= k + 1) {
                                new_dp[end] = max(new_dp[end], dp[k] + current_sum);
                            }
                        }
                    }
                }
            }
        }

        swap(dp, new_dp); // Move new_dp to dp for the next iteration
    }

    // Return maximum profit achievable after n days
    return *max_element(dp.begin(), dp.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<long long>> A(n, vector<long long>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> A[i][j];

        long long result = maxProfit(n, m, A);
        cout << result << '\n';
    }

    return 0;
}
