#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
using namespace __gnu_pbds; 
using namespace std;

#define int long long
// #define ll long long
// typedef long long int int64;
#define endl "\n" // for i- r
#define INF LLONG_MAX
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define setbits(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_ctz(x)
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set; //m - eq // order_of_key(k) { <k } // *find_by_order(i) { 0-based }

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
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using pii = pair<int,int>;
using vpii = vector<pii>;
using vvb = vector<vb>;
template <class T>
void inp(vector<T> &v) { int n=v.size();for(int i=0;i<n;i++) cin>>v[i];}
template <class T>
void display(vector<T> &v) {  for (auto x : v) cout << x << " "; cout << endl; }

const int M= MOD;// change 
vi fact,ifact;
void prec(int maxx=1e6) {
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
 
int ncr(int n, int r) { if(r>n) return 0; int val = mod_mul(fact[n],ifact[n-r],M); val = mod_mul(val,ifact[r], M); return val;}

// utitily
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// ---yo---
int p,q;
int x,y;
// int cnt;

void func(int p1,int q1,int &cnt){
    int xx= abs(x-p1)+ abs(y-q1);

    if(xx<cnt || cnt==-1){
        cnt = xx;
        p=p1;
        q=q1;
    }
}


void solve(){
    cin>>x>>y;
    
    p=0;
    q=0;
    int cnt=-1;

    func(x,y&(~x),cnt);
    func(x&(~y),y,cnt);

    for(int i=0;i<32;i++){
        int bit= (1LL<<i);
        int k= (1LL<<(i+1))-1;
        k= ~k;

        if(!(x&bit)){
            int p1= (x&k)|(bit);
            int q1= y&(~p1);

            func(p1,q1,cnt);
        }
        
        if(!(y&bit)){
            int p1= (y&k)|(bit);
            int q1= x&(~p1);

            func(q1,p1,cnt);
        }

        if((x&bit)){
            int p1= (x&k)|(bit-1);
            int q1= y&(~p1);

            func(p1,q1,cnt);
        }
        
        if((y&bit)){
            int p1= (y&k)|(bit-1);
            int q1= x&(~p1);

            func(q1,p1,cnt);
        }

    }

    cout<<p<<" "<<q<<endl;
    return ;

}

void solve2(){}

int32_t main(){
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
        // solve2();
    }

}

// dsu template
const int mxN=1e5+1;
 
int parent[mxN];
int siz[mxN];
 
void make_set(int v) {
    parent[v]=v;
    siz[v]=1;
}
 
int find_set(int v) {
    return(v==parent[v]) ? v : parent[v] = find_set(parent[v]);
}
 
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    parent[b] = a;
    siz[a] += siz[b];
    siz[b] = 0;
}
 
int get_size(int v) {
    return siz[find_set(v)];
}