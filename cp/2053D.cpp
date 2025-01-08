#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;

ll mul_mod(ll a, ll b) {
    return (__int128)a * b % MOD;
}

// Optimized solution for maximum product
ll calculate_max_product(const vector<ll>& a, const vector<ll>& b) {
    int n = a.size();
    vector<ll> sorted_a = a;
    vector<ll> sorted_b = b;
    sort(sorted_a.begin(), sorted_a.end());
    sort(sorted_b.begin(), sorted_b.end());
    
    ll result = 1;
    // Pair smallest value from one array with largest value from another
    for(int i = 0; i < n; i++) {
        ll min_val = min(sorted_a[i], sorted_b[n-1-i]);
        result = mul_mod(result, min_val);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n, q;
        cin >> n >> q;
        
        vector<ll> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        
        cout << calculate_max_product(a, b);
        
        for(int i = 0; i < q; i++) {
            int o, x;
            cin >> o >> x;
            x--; // Convert to 0-based indexing
            
            if(o == 1) a[x]++;
            else b[x]++;
            
            cout << " " << calculate_max_product(a, b);
        }
        cout << "\n";
    }
    
    return 0;
}