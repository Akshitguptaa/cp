#include <bits/stdc++.h>
using namespace std;

double binToDec(const string &s) {
    int d = 0;
    for (char bit:s) {
        d = d*2+(bit-'0');
    }
    return d;
}

double dist(double r1, double g1, double b1, double r2, double g2, double b2) {
    return (r1 - r2) * (r1 - r2) + (g1 - g2) * (g1 - g2) + (b1 - b2) * (b1 - b2);
}

int main() {
    int t;
    cin >> t;
    
    vector<string> results;

    while (t--) {
        string s;
        cin >> s;

        double r = binToDec(s.substr(0, 8));
        double g = binToDec(s.substr(8, 8));
        double b = binToDec(s.substr(16, 8));

        vector<pair<string, vector<double>>> c = {
            {"Black", {0, 0, 0}},
            {"White", {255, 255, 255}},
            {"Red", {255, 0, 0}},
            {"Green", {0, 255, 0}},
            {"Blue", {0, 0, 255}}
        };

        vector<pair<double, string>> d;
        for (auto &p : c) {
            double r2 = p.second[0], g2 = p.second[1], b2 = p.second[2];
            d.push_back({dist(r, g, b, r2, g2, b2), p.first});
        }

        sort(d.begin(), d.end());
        double minD = d[0].first;
        string res = d[0].second;
        bool amb = false;

        for (size_t i = 1; i < d.size(); i++) {
            if (d[i].first == minD) {
                amb = true;
                break;
            }
        }

        results.push_back(amb ? "Ambiguous" : res);
    }

    for (const string &res : results) {
        cout << res << endl;
    }

    return 0;
}