//// AKSHIT - template ////

#include <bits/stdc++.h>
// #include<chrono>
#include<unordered_set>

using namespace std;
typedef long long int int64;
typedef unsigned long long int uint64;

#define int long long
#define endl "\n"
#define INF LLONG_MAX
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define setbits(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_ctz(x)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define rall(x) x.rbegin(), x.rend()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = b - 1; i >= a; i--)

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
vector<bool> sieve(int n) { vector<bool> prime(n+1,true); for (int p = 2; p * p <= n; p++) { if (prime[p] == true) { for (int i = p * p; i <= n; i += p) prime[i] = false; } } return prime;} 

// vector operationss
using vi = vector<int>;
using vb = vector<bool>;
using v32 = vector<int32_t>;
template <class T>
void debug(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }
template <class T>
void inp(vector<T> &v) { int n=v.size();for(int i=0;i<n;i++) cin>>v[i];}
template <class T>
void display(vector<T> &v) {  for (auto x : v) cout << x << " "; cout << endl; }

// utitily
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

int bb(vector<int>& k, int j) {
    int count = 0;
    while (j > 1) {
        for (int i = 0; i < j - 1; i++) {
            if (k[i + 1] < k[i]) {
                int temp = k[i];
                k[i] = k[i + 1];
                k[i + 1] = temp;
                count++;
            }
        }
        j--;
    }
    return count;
}

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    unordered_set<int> a2;
    unordered_set<int> b2;
    unordered_map<int, int> b3;

    vector<int> b(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a2.insert(a[i]);
    }
    
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b3[b[i]] = i;
        b2.insert(b[i]);
    }

    if (a2 == b2) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            int g = a[i];
            int in = b3[g];
            if (in < i) {
                cout << "NO" << endl;
                return;
            }
            if (in > i) {
                int temp = b[i];
                b[i] = b[in];
                b[in] = temp;
                b3[b[i]] = i;
                b3[b[in]] = in;
                count++;
            }
        }
        if (count % 2 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        cout << "NO" << endl;
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
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}