#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAX = 200005;

int n, m;
vector<pair<int, pair<int, int>>> seg[MAX];
long long dp[MAX], prod[MAX];

long long modpow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int l, r, p, q;
        cin >> l >> r >> p >> q;
        seg[r].push_back({l, {p, q}});
    }

    prod[0] = 1;
    for (int i = 1; i <= m; i++) {
        prod[i] = prod[i - 1];
        for (auto &[l, pq] : seg[i]) {
            prod[i] = (prod[i] * (pq.second - pq.first) % MOD) * modpow(pq.second, MOD - 2) % MOD;
        }
    }

    dp[0] = prod[m];

    for (int i = 1; i <= m; i++) {
        dp[i] = 0;
        for (auto &[l, pq] : seg[i]) {
            long long add = dp[l - 1] * pq.first % MOD * modpow(pq.second, MOD - 2) % MOD;
            add = add * modpow((pq.second - pq.first) * modpow(pq.second, MOD - 2) % MOD, MOD - 2) % MOD;
            dp[i] = (dp[i] + add) % MOD;
        }
    }

    cout << dp[m] << "\n";

    return 0;
}