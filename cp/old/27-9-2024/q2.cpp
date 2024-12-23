#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

#define ll long long

unordered_map<ll, ll> freq(const vector<ll>& v1, ll n) {
    unordered_map<ll, ll> mp;
    for (ll i = 1; i <= n; i++) {
        ll len = (i-1) * (n - i + 1) + (n - i);
        mp[len]++;
        if (i < n) {
            ll gap = v1[i]-v1[i - 1] - 1;
            if (gap > 0) {
                mp[i*(n-i)] += gap;
            }
        }
    }
    return mp;
}

vector<string> func(vector<ll> v2,unordered_map<ll, ll> mp) {
    vector<string> ans;
    for (ll i : v2) {
        if (mp.count(i)) {
            ans.push_back(to_string(mp.at(i)));
            continue;
        }
        ans.push_back("0");
    }
    return ans;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll t;
    cin >> t;
    vector<string> ans;
    while (t--) {
        ll n, q;
        cin >> n >> q;
        vector<ll> v1(n);
        for (ll& i : v1) {
            cin >> i;
        }
        vector<ll> v2(q);
        for (ll& i : v2) {
            cin >> i;
        }
        unordered_map<ll, ll> mp = freq(v1, n);
        vector<string> v = func(v2, mp);

        string str;
        int s1= v.size();
        for (int i = 0; i < s1; i++) {
            str += v[i];
            if (i < v.size() - 1) {
                str += " ";
            }
        }
        ans.push_back(str);
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i < ans.size() - 1) {
            cout << "\n";
        }
    }
    return 0;
}
