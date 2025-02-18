#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll triangle_area(ll x1, ll x2, ll x3) {
    // Calculate the area using the points (x1, 0), (x2, 2), and (x3, 2)
    return abs(x3 - x2) * 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<ll> a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        vector<ll> scores;
        // While there are enough points to perform at least one operation:
        while (n >= 1 && m >= 2) {
            // The largest area comes from the two points in b with the largest difference
            ll area = triangle_area(b[0], b[1], b[m - 1]);
            scores.push_back(area);

            // Remove the points involved in this operation
            b.erase(b.begin()); // Remove the first point in b
            b.erase(b.end() - 1); // Remove the last point in b
            a.erase(a.begin()); // Remove one point from a

            // Update n and m
            n--; m -= 2;
        }

        int kmax = scores.size();
        cout << kmax << "\n";
        if (kmax > 0) {
            for (int i = 0; i < kmax; i++) {
                cout << scores[i] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
