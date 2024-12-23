//// AKSHIT - template ////

#include <bits/stdc++.h>
#include<chrono>
#include<unordered_set>

using namespace std;
typedef long long int int64;
typedef unsigned long long int uint64;

#define int long long
#define endl "\n"
#define INF LLONG_MAX
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

// i/o
static const auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();

// string operations
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }

// math
int gcd(int a,int b) { if (b==0) return a; return gcd(b, a%b); }
int lcm(int a,int b) { return a/gcd(a,b)*b; }
int power_mod(int a, int b, int mod) { int res = 1; a %= mod; while(b>0) {if (b & 1) res = res * a % mod;a = a * a % mod; b >>= 1;} return res;}
bool prime(int a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
int mod_mul(int a, int b, int m) {return (a%m * b%m)%m;}
int mod_expo(int a, int b, int m){ if(b==0) return 1; int res=mod_expo(a,b/2,m); res=mod_mul(res,res,m); if(b%2==1) res=mod_mul(res,a,m);return res;}
int mod_inv(int a, int m) {return mod_expo(a,m-2,m);}//fermat's theorem
int mod_div(int a, int b, int m) {return mod_mul(a,mod_inv(b,m),m);}

// vector operationss
using vi = vector<int>;
using vb = vector<bool>;
using v32 = vector<int32_t>;
template <class T>
void debug(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }
template <class T>
void inp(vector<T> &v) { for(int i=0;i<v.size();i++) cin>>v[i];}
template <class T>
void display(vector<T> &v) {  for (auto x : v) cout << x << " "; cout << endl; }

// utitily
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// void solve(){
//     int n;
//     cin>>n;
//     vector<pair<int,int>> v(n-1);
//     for(int i=0;i<n;i++){
//         cin>>v[i].first;
//         cin>>v[i].second;
//     }
    
// }
int calcSum(vi &p) {
    int n = p.size(), totalSum = 0;
    for(int i=0;i<n;i++) {
        int minVal = p[i];
        for(int r=i;r<n;r++) {
            minVal = min(minVal, p[r]);
            totalSum += minVal;
        }
    }
    return totalSum;
}

void genPerms(vi &p, int l, int r, vector<pair<int, vi>> &sums) {
    if (l == r) {
        int sum = calcSum(p);
        sums.push_back({sum, p});
    } else {
        for(int i=l;i<=r;i++){
            swap(p[l], p[i]);
            genPerms(p, l + 1, r, sums);
            swap(p[l], p[i]);
        }
    }
}

void findKth(int n, int k) {
            vi p(n);
            for(int i=0;i<n;i++) p[i] = i + 1;
            vector<pair<int, vi>> sums;
            genPerms(p, 0, n - 1, sums);
        sort(sums.begin(),sums.end(), [](pair<int, vi> &a, pair<int, vi> &b) {
            if (a.first != b.first) return a.first > b.first; 
            return a.second < b.second;                   
            });

                int maxSum = sums[0].first;
                vector<vi> maxPerms;
                for (auto &e : sums) {
                    if (e.first == maxSum) maxPerms.push_back(e.second);
                }
                sort(maxPerms.begin(),maxPerms.end());
                if (k <= maxPerms.size()) {
                    for (auto val : maxPerms[k - 1]) cout << val << " ";
                    cout << endl;
                } else {
                    cout << -1 << endl;
                }
}

void solve() {
    int n, k;
    cin >> n >> k;
    if (n > 10) {
        cout << -1 << endl;
    } else {
        findKth(n, k);
    }
}

void solve2(){}

int32_t main(){
    auto begin = chrono::high_resolution_clock::now();
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        solve();
        // solve2();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}