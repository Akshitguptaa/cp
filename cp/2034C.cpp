#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> bad(n, vector<int>(m, 0));

    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    queue<pair<int, int>> q;

    for (int i = 0; i < n; ++i) {
        if (s[i][0] == 'L') {
            bad[i][0] = 1;
            q.push({i, 0});
        }
        if (s[i][m - 1] == 'R') {
            bad[i][m - 1] = 1;
            q.push({i, m - 1});
        }
    }
    for (int i = 0; i < m; ++i) {
        if (s[0][i] == 'U') {
            bad[0][i] = 1;
            q.push({0, i});
        }
        if (s[n - 1][i] == 'D') {
            bad[n - 1][i] = 1;
            q.push({n - 1, i});
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x > 0 && bad[x - 1][y] == 0 && s[x - 1][y] == 'D') {
            bad[x - 1][y] = 1;
            q.push({x - 1, y});
        }
        if (x < n - 1 && bad[x + 1][y] == 0 && s[x + 1][y] == 'U') {
            bad[x + 1][y] = 1;
            q.push({x + 1, y});
        }
        if (y > 0 && bad[x][y - 1] == 0 && s[x][y - 1] == 'R') {
            bad[x][y - 1] = 1;
            q.push({x, y - 1});
        }
        if (y < m - 1 && bad[x][y + 1] == 0 && s[x][y + 1] == 'L') {
            bad[x][y + 1] = 1;
            q.push({x, y + 1});
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (bad[i][j] == 0 && s[i][j] != '?') {
                ans++;
            } else if (bad[i][j] == 0) {
                bool flag = true;
                if (i > 0) flag &= bad[i - 1][j];
                if (j > 0) flag &= bad[i][j - 1];
                if (i < n - 1) flag &= bad[i + 1][j];
                if (j < m - 1) flag &= bad[i][j + 1];
                if (!flag) ans++;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
