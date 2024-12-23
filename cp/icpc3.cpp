#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;
const int MAX_Y = 4000006; // Maximum Y value

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Read number of test cases
    int t;
    cin >> t;
    
    // Store all Y values that need to be processed
    vector<int> Y_values(t);
    int max_Y = 0;
    for (int i = 0; i < t; ++i) {
        cin >> Y_values[i];
        max_Y = max(max_Y, Y_values[i]);
    }

    // Initialize DP array where dp[i] is the number of ways to achieve score i
    vector<long long> dp(max_Y + 1, 0);
    dp[0] = 1; // There is exactly 1 way to achieve score 0 (doing nothing)

    // Process the dynamic programming states
    for (int value = 2; value <= max_Y; value *= 2) {
        for (int score = max_Y; score >= value; --score) {
            dp[score] = (dp[score] + dp[score - value]) % MOD;
        }
    }

    // Output results for each test case
    for (int i = 0; i < t; ++i) {
        cout << dp[Y_values[i]] << "\n";
    }

    return 0;
}
