//// AKSHIT - template ////

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> 

using namespace __gnu_pbds; 
using namespace std;
typedef long long int int64;

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
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = b - 1; i >= a; i--)
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

// i/o
static const auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();

// math
int gcd(int a,int b) { if (b==0) return a; return gcd(b, a%b); }
int lcm(int a,int b) { return a/gcd(a,b)*b; }
int power_mod(int a, int b, int mod) { int res = 1; a %= mod; while(b>0) {if (b & 1) res = res * a % mod;a = a * a % mod; b >>= 1;} return res;}
bool prime(int a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
int mod_mul(int a, int b, int m) {return (a%m * b%m)%m;}
int moio(int a, int b, int m){ if(b==0) return 1; int res=moio(a,b/2,m); res=mod_mul(res,res,m); if(b%2==1) res=mod_mul(res,a,m);return res;}
int mod_inv(int a, int m) {return moio(a,m-2,m);}//fermat's theorem
int mod_div(int a, int b, int m) {return mod_mul(a,mod_inv(b,m),m);}
vector<bool> sieve(int n) { vector<bool> prime(n+1,true); for (int p = 2; p * p <= n; p++) { if (prime[p] == true) { for (int i = p * p; i <= n; i += p) prime[i] = false; } } return prime;} 

// vector operationss
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using pii = pair<int,int>;
using vpii = vector<pii>;
template <class T>
void debug(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }
template <class T>
void inp(vector<T> &v) { int n=v.size();for(int i=0;i<n;i++) cin>>v[i];}
template <class T>
void display(vector<T> &v) {  for (auto x : v) cout << x << " "; cout << endl; }

// utitily
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

const int M = 1e9 + 7;

vi fact,ifact;
void prec(int maxx=60) {
    fact.assign(maxx+1,1);
    ifact.assign(maxx+1,1);
    for(int i=1;i<=maxx;i++){
        fact[i] = fact[i-1] * i % M;
    }
    ifact[maxx] = mod_div(1,fact[maxx],M);
 
    for(int i=maxx-1;i>=0;i--){
        ifact[i] = mod_mul(ifact[i+1] ,(i+1),M);
    }
}
 
int ncr(int n, int k) {
    if(k<0){
        return 0;
    }
    if(k==0){
        return 1;
    }
    
    n %= M;
    if(n==0 && k>0){
        return 0;
    }

    int num = 1;
    for (int i = 0; i < k; i++) {
        num = (num * (n + k - 1 - i)) % M;
    }

    return (num * ifact[k]) % M;
}

map<int,int> factorize(int n){
    map<int,int> fac;
    for(int i=2;i*i <= n;i++){
        while(n%i==0) {
            fac[i]++;
            n/= i;
        }
    }
    if(n>1){
        fac[n]++;
    }
    return fac;
}

int n, a, b;
vpii factors;
int ans; 

void func(int idx, int curr, int prod) {
    if (idx == factors.size()) {
        ans = (ans + prod) % M;
        return;
    }

    auto [x,y]= factors[idx];
    int pow = 1;

    for(int i=0; i<=y; i++){ 
        if(pow>1 && curr>a/pow){
            break;
        }

        int ways= ncr(n,i);
        int way1= ncr(n,y-i);
        
        int val = (ways * way1 % M);
        int val2 = (prod * val % M);

        func(idx+1, curr*pow, val2);
        
        if(i<y){
            pow*=x;
        }
    }
}

void solve() {
    cin>>n>>a>>b;
    
    auto mp = factorize(b);
    factors.assign(all(mp));

    ans= 0;
    func(0,1,1);
    cout<<ans<<endl;
}


void solve2(){}

int32_t main(){
    freopen("in.txt",  "r", stdin);
    freopen("out.txt", "w", stdout);

    prec();
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
        // solve2();
    }

}

//END