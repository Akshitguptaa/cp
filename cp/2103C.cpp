#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF LLONG_MAX
#define inf LLONG_MIN
#define pb push_back
#define maxe *max_element
#define mine *min_element
#define mod 1000000007
#define MOD 998244353
bool f2(vector<ll>& v, ll k) {
    int i = 0, cnt = 0, ind1 = -1, ind2 = -1, n = v.size();
    while(i < n) {
        if(v[i] <= k) cnt++;
        else cnt--;
        if(cnt >= 0) {
            ind1 = i;
            break;
        }
        i++;
    }
    i = n-1;
    cnt = 0;
    while(i >= 0) {
        // cout << v[i] << " " << k << endl;
        if(v[i] <= k) cnt++;
        else cnt--;
        if(cnt >= 0) {
            ind2 = i;
            break;
        }
        i--;
    }
    // cout << ind1 << " " << ind2 << endl;
    if(ind1 != -1 && ind2 != -1 && ind1 < ind2) {
        return true;
    }
    return false;
}
bool f1(vector<ll>& v, ll k) {
    int i = 0, n = v.size(), cnt = 0, check = 0;
    while(i < n) {
        if(v[i] <= k) cnt++;
        else cnt--;
        if(cnt >= 0) {
            check++;
            i++;
            break;
        }
        i++;
    }
    cnt = 0;
    if(i < n && v[i] > k) i++;
    while(i < n) {
        if(v[i] <= k) cnt++;
        else cnt--;
        if(cnt >= 0) {
            check++;
            break;
        }
        i++;
    }
    return check == 2;
}
void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n), rv;
    for(int i = 0; i < n; i++) cin >> v[i];
    rv = v;
    reverse(rv.begin(), rv.end());
    // cout << f1(v, k) << " " << f1(rv, k) << " " << f2(v, k) << endl;
    if(f1(v, k) || f1(rv, k) || f2(v, k)) cout << "yes\n";
    else cout << "no\n";
}
int main() {
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
}