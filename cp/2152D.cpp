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
// #define INF LLONG_MAX
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define setbits(x) __builtin_popcountll(x)
#define trailzero(x) __builtin_ctz(x)
#define pb push_back
// #define mp make_pair
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
vb s=sieve(100);
template <class T>
void debug(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }
template <class T>
void inp(vector<T> &v) { int n=v.size();for(int i=0;i<n;i++) cin>>v[i];}
template <class T>
void display(vector<T> &v) {  for (auto x : v) cout << x << " "; cout << endl; }

// utitily
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// segment tree
vector<int> t;
vector<int> t1;
#define INF ((1LL << 32) - 1)
 
int combine(int a, int b) {
    return a + b;
}
 
void build(vi & tree,vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(tree, a, v * 2, tl, tm);
        build(tree, a, v * 2 + 1, tm + 1, tr);
        tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    }
}
 
int func(vi& tree,int v,int tl,int tr,int l,int r){
    if(l > r){
        return 0;
    }
    if(l==tl && r==tr){
        return tree[v];
    }
    int tm= (tl+tr)/2;
 
    return combine(func(tree, v*2, tl, tm, l, min(r,tm)), func(tree,v*2+1, tm+1, tr, max(l,tm+1),r));
}

unordered_map<int,int> mp;

int recc(int x){
    if(x==1){
        return 0;
    } 
    if(x<=3){
        return 1;}
    if(mp.count(x)){
        return mp[x];
    }
    return mp[x]= 1+recc(x/2+1);
}

void solve(){
    int n,q;
    cin>>n>>q;
    
    vi v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    
    vi pr(n+1,0);
    vi pr1(n+1,0);
    vi pr2(n+1,0);
    for(int i=1;i<=n;i++){
        pr[i] = pr[i-1]+log2(v[i]);
        int x = log2(v[i]);

        pr1[i] = pr1[i-1];
        pr2[i] = pr2[i-1];

        if(v[i] == (1LL<<x)){
            continue;
        }else if(v[i] == (1LL<<x)+1){
            pr1[i]++;
        }else{
            pr2[i]++;
        }
    }
    
    while(q--){
        int l,r; 
        cin>>l>>r;
        int val = pr1[r]-pr1[l-1];

        int ans=pr[r] - pr[l-1] + pr2[r] - pr2[l-1] + (val>>1);
        cout<<ans<<endl;
    }

    // vi v(n);
    // vi vec(n,0);
    // for(int i=0;i<n;i++){
    //     v[i]= recc(v1[i]);
    //     if(v1[i]>2){
    //         if(((v1[i]-1)&(v1[i]-2)) == 0){
    //             vec[i]=1;
    //         }
    //     }
    // }

    // t.assign(4 * n, 0);
    // t1.assign(4 * n, 0);

    // build(t,v,1, 0,n-1);
    // build(t1,vec,1,0,n-1);

    // for(int i=0;i<q;i++){
    //     int l,r;
    //     cin>>l>>r;
        
    //     int val = func(t,1,0,n-1, l-1, r-1);
    //     int val1 = func(t1,1, 0, n - 1, l - 1, r - 1);
        
    //     int ans= val + val1 / 2;
    //     cout<<ans<<endl;
    // }

}

void solve2(){}

int32_t main(){
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        mp.clear();
        solve();
        // solve2();
    }

}

//END