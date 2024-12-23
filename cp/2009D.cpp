#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> points(n);
        unordered_map<int, int> yCount, xCount;

        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            points[i] = {x, y};
            xCount[x]++;
            yCount[y]++;
        }

        ll ans = 0;

        for (auto point : points) {
            int x_r = point.first;
            int y_r = point.second;

            ll count_x = xCount[x_r];
            ll count_y = yCount[y_r];

            ans += (count_x - 1) * (count_y - 1);
        }

        cout << ans << endl;
    }
    return 0;
}
