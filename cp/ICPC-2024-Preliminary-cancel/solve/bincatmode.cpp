#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 998244353;

long long modpow(long long a, unsigned long long e) {
    long long r = 1 % MOD;
    a %= MOD;
    while (e) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}
long long inv(long long x) { return modpow((x%MOD+MOD)%MOD, MOD - 2); }

// sum_{i=0}^{len-1} r^i = (1 - r^len) / (1 - r)
inline long long geo_sum(long long r, unsigned long long len) {
    if (len == 0) return 0;
    long long num = (1 - modpow(r, len) + MOD) % MOD;
    long long den = (1 - r + MOD) % MOD;
    return (num * inv(den)) % MOD;
}

// Contribution for a fixed bit b in block [L, L+m-1], with base B=10^k
// returns  Σ_{t=0..m-1} bit_b(L+t) * (B^{-1})^t   (mod MOD)
long long contrib_bit(unsigned long long L, unsigned long long m, int b, long long B) {
    if (m == 0) return 0;
    unsigned long long q = 1ULL << b;         // ones run length
    unsigned long long P = q << 1;            // period
    long long r = inv(B);                     // B^{-1} mod
    long long total = 0;

    unsigned long long off = L % P;           // position inside period
    unsigned long long t0 = 0;                // current t index from start
    long long inv_den = inv((1 - r + MOD) % MOD);

    // 1) Skip initial zeros part (if starting in first half)
    if (off < q) {
        unsigned long long take = min(q - off, m);
        off += take; m -= take; t0 += take;
    }
    if (m == 0) return total;

    // 2) First partial ones segment (at most q long)
    {
        unsigned long long first_len = min(P - off, m); // ≤ q
        long long num = (1 - modpow(r, first_len) + MOD) % MOD;
        total = (total + modpow(r, t0) * num) % MOD;
        total = (total * inv_den) % MOD;

        m -= first_len; t0 += first_len; off = (off + first_len) % P; // now at boundary
    }

    if (m == 0) return total;

    // 3) Full periods: each has zeros(q) then ones(q)
    unsigned long long full = m / P;
    if (full > 0) {
        long long segsum = geo_sum(r, q);        // sum of ones in a period: r^0 + ... + r^{q-1}
        long long rr = modpow(r, P);             // ratio per period
        long long geom = geo_sum(rr, full);      // 1 + rr + ... + rr^{full-1}
        // ones blocks start at t = t0 + q in each period
        total = (total + modpow(r, t0 + q) * ((segsum * geom) % MOD)) % MOD;

        t0 += full * P;
        m  -= full * P;
    }

    // 4) Trailing remainder: zeros first (length ≤ q), then ones (length ≤ q)
    if (m > q) {
        unsigned long long ones_len = min(q, m - q);
        long long num = (1 - modpow(r, ones_len) + MOD) % MOD;
        total = (total + modpow(r, t0 + q) * num) % MOD;
        total = (total * inv_den) % MOD;
    }

    return (total % MOD + MOD) % MOD;
}

// Compute S for a k-block [L..R] (inclusive), where all numbers have k bits
// Returns (S, B, m) with B = 10^k, m = R-L+1
tuple<long long,long long,unsigned long long> S_block(unsigned long long L, unsigned long long R, int k) {
    unsigned long long m = R - L + 1;
    long long B = modpow(10, k);
    long long Bpow = (m >= 1 ? modpow(B, m - 1) : 1);
    long long total = 0;

    for (int b = 0; b < k; ++b) {
        long long weight = modpow(10, b);                       // 10^b
        long long inner  = contrib_bit(L, m, b, B);             // Σ bit * (B^{-1})^t
        long long add    = (((weight * Bpow) % MOD) * inner) % MOD;
        total += add;
        if (total >= MOD) total -= MOD;
    }
    return {total % MOD, B, m};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        unsigned long long n;
        cin >> n;

        long long ans = 0;
        unsigned long long L = 1;
        for (int k = 1; L <= n; ++k, L <<= 1) {
            unsigned long long R = min(n, ( (1ULL<<k) - 1 ));
            auto [S, B, m] = S_block(L, R, k);
            // append the whole block in one go
            ans = ( (ans * modpow(B, m)) % MOD + S ) % MOD;
        }
        cout << (ans % MOD + MOD) % MOD << '\n';
    }
    return 0;
}
