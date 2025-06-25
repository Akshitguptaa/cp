#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int f(int x, int y) {
    return (x % y) + (y % x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        vector<int> res;
        int maxVal = a[0];
        int maxBeauty = 0;

        res.push_back(0); // first element, beauty = 0

        vector<int> seen = {a[0]};  // for rare full scans

        for (int i = 1; i < n; ++i) {
            int v = a[i];
            int currBeauty = maxBeauty;

            // Check for easy max using maxOverHalf
            if (maxVal > v / 2) {
                currBeauty = max(currBeauty, v);
            }

            // Rare full scan only if v >= 2 * maxVal
            if (v >= 2 * maxVal) {
                for (int x : seen) {
                    currBeauty = max(currBeauty, f(x, v));
                }
            }

            res.push_back(currBeauty);
            seen.push_back(v);
            maxVal = max(maxVal, v);
            maxBeauty = max(maxBeauty, currBeauty);
        }

        for (int x : res) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
