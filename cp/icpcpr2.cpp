#include <bits/stdc++.h>
#include <chrono>
#include <unordered_set>

using namespace std;
typedef long long int int64;
typedef unsigned long long int uint64;

#define int long long
#define endl "\n"
#define INF LLONG_MAX
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

static const auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();

void solve() {
    int n;
    cin >> n;
    
    vector<int> c(n);
    vector<vector<int>> pos(n);
    
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    
    for (int i = 0; i < n; i++) {
        pos[i].resize(c[i]);
        for (int j = 0; j < c[i]; j++) {
            cin >> pos[i][j];
        }
    }

    map<int, int> lm, rm;
    int coll = 0;
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            for (int p : pos[i]) {
                rm[p]++;
            }
        }
        else if (i == n - 1) {
            for (int p : pos[i]) {
                if (rm[p] > 0) {
                    coll += rm[p];
                }
                lm[p]++;
            }
        }
        else {
            int lc = 0, rc = 0;
            for (int p : pos[i]) {
                if (lm[p] > 0) lc += lm[p];
            }
            for (int p : pos[i]) {
                if (rm[p] > 0) rc += rm[p];
            }
            
            if (lc <= rc) {
                for (int p : pos[i]) {
                    if (lm[p] > 0) coll += lm[p];
                    lm[p]++;
                }
            } else {
                for (int p : pos[i]) {
                    if (rm[p] > 0) coll += rm[p];
                    rm[p]++;
                }
            }
        }
    }

    cout << coll << endl;
}

void solve2() {}

int32_t main() {
    auto begin = chrono::high_resolution_clock::now();

    solve();

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
}
