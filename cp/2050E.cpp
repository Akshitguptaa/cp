#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minChanges(string a, string b, string c) {
    int n = a.length(), m = b.length();
    // DP table initialized to a large number.
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1000000000));

    dp[0][0] = 0; // No characters from a and b, no changes

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            int k = i + j; // k is the position in string c
            
            // If we pick from a
            if (i > 0) {
                int change = (a[i - 1] == c[k] ? 0 : 1);
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + change);
            }
            
            // If we pick from b
            if (j > 0) {
                int change = (b[j - 1] == c[k] ? 0 : 1);
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + change);
            }
        }
    }

    // The result will be in dp[n][m], where n is the length of a and m is the length of b
    return dp[n][m];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b, c;
        cin >> a >> b >> c;
        cout << minChanges(a, b, c) << endl;
    }
    return 0;
}
