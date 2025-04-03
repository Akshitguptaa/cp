//// AKSHIT - template ////

#include <bits/stdc++.h>

using namespace std;
typedef long long int int64;
typedef unsigned long long int uint64;

#define int long long
#define enl "\n"
// #define INF LLONG_MAX
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define setbits(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_ctz(x)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.en()
#define rall(x) x.rbegin(), x.ren()
#define rall(x) x.rbegin(), x.ren()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = b - 1; i >= a; i--)

// i/o
static const auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();

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
void display(vector<T> &v) {  for (auto x : v) cout << x << " "; cout << enl; }

// utitily
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// segment tree
vector<int> t;
#define INF ((1LL << 32) - 1)

int combine(int a, int b) {
    return a & b;
}

void build(vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

int func(int v,int tl,int tr,int l,int r){
    if(l > r){
        return INF;
    }
    if(l==tl && r==tr){
        return t[v];
    }
    int tm= (tl+tr)/2;

    return combine(func(v*2, tl, tm, l, min(r,tm)), func(v*2+1, tm+1, tr, max(l,tm+1),r));
}

void solve(){
    int n;
    cin>>n;
    vi v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }

    t.resize(4*n);
    build(v,1,1,n);

    int q;
    cin>>q;

    while(q--){
        int l1,k;
        cin>>l1>>k;

        if(v[l1]<k){
            cout<<-1<<" ";
            continue;
        }
        int l=l1;
        int r=n;

        int ans=l1;
        while(l<= r){
            int mid = l+(r-l)/2;
            if (func(1,1,n,l1,mid) >= k){
                ans = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        cout<<ans<<" ";
    }
    cout<<endl;
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

    auto en = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(en - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}