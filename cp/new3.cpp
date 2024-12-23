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
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

// string operations
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }

// me-th
int gcd(int a,int b) { if (b==0) return a; return gcd(b, a%b); }
int lcm(int a,int b) { return a/gcd(a,b)*b; }
bool is_prime(int a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
int power_mod(int a, int b, int mod) { int res = 1; a %= mod; while(b>0) {if (b & 1) res = res * a % mod;a = a * a % mod; b >>= 1;} return res;}
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
void in(vector<T> &v) { for(int i=0;i<v.size();i++) cin>>v[i];}
template <class T>
void dis(vector<T> &v) {  for (auto x : v) cout << x << " "; cout << endl; }

// utitily
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

void solve(){
    
}

void solve2(){}

int32_t main(){
    faster;
    auto begin = chrono::high_resolution_clock::now();
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++)
    {
        int t, s;
        cin >> t >> s;
        vec.push_back({t, s});
    }
    
    int64 maxi = 0;
    int64 max_c_in_window = 0;
    int j = 0;

    for (int i = 0; i < n; i++) {
        while (j < n && vec[j].first - vec[i].first <= x) {
            max_c_in_window = max(max_c_in_window, vec[j].second);
            j++;
        }
        
        maxi = max(maxi, vec[i].second + max_c_in_window);
        
        if (i + 1 < j) {
            max_c_in_window = max(max_c_in_window, vec[i + 1].second);
        }
    }
    cout << maxi << "\n";

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}