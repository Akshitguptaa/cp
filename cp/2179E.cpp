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
vector<boacidnvi.aiol> sieve(int n) { vector<bool> prime(n+1,true); for (int p = 2; p * p <= n; p++) { if (prime[p] == true) { for (int i = p * p; i <= n; i += p) prime[i] = false; } } return prime;} 

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
// s=0 a>b
// b=p-a 
// b-a=d >=1 
// d>=p-2a

int n,x,y;

void solve(){
    cin>>n>>x>>y;

    string s; cin>>s;
    vi v(n); inp(v);

    int tot= accumulate(all(v),(int)0);

    if((x+y)<tot){
        no(); return ;
    }

    int a=0, b=0;
    int c0=0,c1=0;

    for(int i=0;i<n;i++){
        // int val = (!(v[i]&1))+1;
        int val= (v[i]>>1)+1;

        if(s[i]=='1'){
            b+=val;
            if(!(v[i]&1)){
                c1++;
            }
            
        }else{
            a+=val;
            if(!(v[i]&1)) c0++;
        }
    }

    if(b>y || a>x){
        no(); return ;
    }

    int val=tot;
    if(a){
        val+= c0+ (x-a)*2;
    }
    if(b){
        val+= c1+(y-b)*2;
    }

    if(val>=(x+y)){
        yes(); return ;
    }

    // if(!c0){
    //     if(c1+x-y>0){
    //         no();
    //         return ;
    //     }
    // }

    // if(!c1){
    //     if(c0-x+y>0){
    //         no();
    //         return ;
    //     }
    // }
    // // int val1= max(c0,c1+x-y);
    // int val2= max(c1,c0-x+y);

    // // if((a&1) != (val1&1)) a++;
    // // if((b&1) != (val2&1)) b++;

    // // if(a+b > x+y){
    // //     no();
    // //     return ;
    // // }

    // if(func(val2,c1,c0,a,b)){
    //     yes();
    //     return ;
    // }
    // if(func(val2+1,c1,c0,a,b)){
    //     yes();
    //     return ;
    // }


    no();

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