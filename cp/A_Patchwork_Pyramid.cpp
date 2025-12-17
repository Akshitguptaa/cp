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
int n,k;
vvi adj;
vector<vpii> vec;
vvi vis;

vi rows= {0,0,1,-1};
vi cols= {1,-1,0,0};
int val;

vpii dfs(int i,int j){
    vis[i][j]=1;
    vpii res;
    res.pb({i,j});

    for(int l=0;l<4;l++){
        int r1= i+rows[l];
        int c1= j+cols[l];
        
        if(r1>=0 && r1<n && c1<=r1 && c1>=0 ){
            if(!vis[r1][c1]){
                auto temp = dfs(r1,c1);
                for(auto a:temp){
                    res.pb(a);
                }
                
                while(res.size()>=k){
                    vec.pb({});
                    for(int m=0;m<k;m++){
                        auto [x,y]= res.back();
                        res.pop_back();

                        adj[x][y]= val;
                        vec[val].pb({x,y});

                    }
                    val++;
                }
            }

        }
    }

    return res;
}

void solve(){
    cin>>n>>k;

    vec= vector<vpii>();
    adj= vvi(n,vi(n,-1));
    vis= vvi(n,vi(n));
    val=0;
    
    auto temp = dfs(0,0);
    
    if(!temp.empty()) {
        vec.pb({});
        for(auto [x,y]: temp){
            adj[x][y] = val;
            vec[val].pb({x,y}) ;

        }
        val++;
    }
    
    cout<<val<<endl;

    vector<char> res(val);
    for(int i=0; i<val; i++) {
        set<char> st;

        for(auto [x,y]: vec[i]){

            for(int l=0;l<4;l++){
                int r1= x+rows[l];
                int c1= y+cols[l];

                if(r1>=0 && r1<n && c1>=0 && c1<=r1){

                    int idx = adj[r1][c1];
                    if(idx != -1 && idx < i){
                        st.insert(res[idx]);
                    }

                }
            }
        }


        char c = 'a';
        while(st.count(c)){
            c++;
        }
        res[i]= c;
    }

    for(int i=0;i<n; i++){
        for(int j=0;j<=i; j++){
            cout<<res[adj[i][j]];
        }

        cout<<endl;
    }
    
}

void solve2(){}

int32_t main(){
    freopen("input.txt",  "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
        // solve2();
    }

}