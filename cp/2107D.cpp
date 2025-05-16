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
int mod_expo(int a, int b, int m){ if(b==0) return 1; int res=mod_expo(a,b/2,m); res=mod_mul(res,res,m); if(b%2==1) res=mod_mul(res,a,m);return res;}
int mod_inv(int a, int m) {return mod_expo(a,m-2,m);}//fermat's theorem
int mod_div(int a, int b, int m) {return mod_mul(a,mod_inv(b,m),m);}
vector<bool> sieve(int n) { vector<bool> prime(n+1,true); for (int p = 2; p * p <= n; p++) { if (prime[p] == true) { for (int i = p * p; i <= n; i += p) prime[i] = 0; } } return prime;} 

// vector operationss
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
template <class T>
void debug(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }
template <class T>
void inp(vector<T> &v) { int n=v.size();for(int i=0;i<n;i++) cin>>v[i];}
template <class T>
void display(vector<T> &v) {  for (auto x : v) cout << x << " "; cout << endl; }

// utitily
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

int bfs(int x,vvi& adj,vb& vis,vi& dis,vi& p,vi& q,int n){
    q.clear();
    q.pb(x);
    dis[x] = 0;
    p[x] = -1;
    
    for(int i=0;i<q.size();i++){
        int curr=q[i];
        for(int y : adj[curr]) {
            if(y!=p[curr] && !vis[y]){
                dis[y]=dis[curr]+1;
                p[y]=curr;
                q.pb(y);
            }
        }
    }

    int t = x;
    int maxi=dis[x];
    for(int i:q) {
        if(dis[i]>maxi || (dis[i]==maxi && i>t)){
            t=i;
            maxi=dis[i];
        }
    }
    return t;
}

void func(int x,vvi& adj,vb& vis,vi& dis,vi& p,vi& q,vector<array<int,3>>& ans,int n){
    for(int v:q){
        dis[v] = -1;
    }
    q.clear();
    
    int a=bfs(x,adj,vis,dis,p,q,n);
    
    for(int v:q){
        dis[v] = -1;
    }

    q.clear();
    
    int b=bfs(a, adj, vis, dis, p, q, n);
    
    ans.pb({dis[b]+1,max(a,b)+1, min(a,b)+1});

    for(int i=b;i!=-1; i=p[i]){
        vis[i]=1;
    }
    
    for (int i = b; i!= -1; i = p[i]) {
        // vis[i]=1;
        for (int y : adj[i]) {
            if(!vis[y]) {
                func(y, adj, vis, dis, p, q, ans, n);
            }
        }
    }
}

// void dfs(int x,vvi& adj,vb& vis,vi& dis,vi& p,vi& q,vector<array<int,3>>& ans,int n){
//     int a=x;
//     bfs(a,adj,vis,dis,p,q,n);
//     a=func(q,dis,a);
    

//     // /
//     bfs(a,adj,vis,dis,p,q,n);
//     int b=func(q,dis,a);
    
//     ans.push_back({dis[b]+1,max(a,b)+1,min(a, b)+1});
    
//    vi vec;
//     for(int i=b; i!=-1; i=p[i]){
//         vec.push_back(i);
//         vis[i]=1;
//     }
    
//     for(int i:vec){
//         for(int y:adj[i]){
//             if(!vis[y]){
//                 dfs(y,adj,vis,dis,p,q,ans,n);
//             }
//         }
//     }
// }

void solve(){
    int n;
    cin >> n;
    
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<array<int,3>> ans;
    vector<bool> vis(n,0);
    vector<int> dis(n,-1),p(n,-1),q;
    q.reserve(n);
    
    
    func(0,adj,vis,dis,p,q,ans,n);
    
    sort(rall(ans));
    for(auto [d,u,v]:ans){
        cout<<d<<" "<<u<<" "<<v<<" ";
    }
    cout<<endl;
}

void solve2(){}

int32_t main(){
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        solve();
        // solve2();
    }

}

//END