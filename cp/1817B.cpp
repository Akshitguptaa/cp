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
vector<bool> sieve(int n) { vector<bool> prime(n+1,true); for (int p = 2; p * p <= n; p++) { if (prime[p] == true) { for (int i = p * p; i <= n; i += p) prime[i] = false; } } return prime;} 

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
int n;
vector<pair<int,int>> edges;

bool func(vvi& adj,int &u,int& n,vi& seen,vi& par,vi& sub,queue<int>& q){
    seen.assign(n,0);
    par.assign(n,-1);
    sub.assign(n,-1);

    // seen[u]=1;
    // queue<int> q;

    // // init
    //     // marking parent
    // for(auto &i:adj[u]){
    //     seen[i]=1;
    //     sub[i]=i;
    //     q.push(i);
    //     par[i]=u;
    // }

    // while(!q.empty()){
    //     auto v=q.front();
    //     q.pop();
    //     for(auto &i:adj[v]){
    //         if(seen[i]){
             
    //             continue;
    //         }

    //         seen[i]=1;
    //         par[i]=v;
    //         sub[i]= sub[v];
    //     }

    // }

    vi nei(n, 0);
    for (auto v : adj[u]) nei[v] = 1;

    par[u] = -2;
    int win = -1;

    for (auto j : adj[u]) {
        if (par[j] == -1) {
            vector<int> que = {j};
            par[j] = u;
            for (int b = 0; b < (int)que.size(); ++b) {
                for (auto to : adj[que[b]]) {
                    if (par[to] == -1) {
                        par[to] = que[b];
                        que.pb(to);
                        if (win == -1 && nei[to]) {
                            win = to;
                        }
                    }
                }
            }
        }
    }

    if (win != -1) {
        edges.pb({u, win});
        int x = win;
        while (x != u) {
            edges.pb({x, par[x]});
            x = par[x];
        }

        vi used(n, 0);
        for (auto& [a, b] : edges) {
            used[a] = 1;
            used[b] = 1;
        }

        vi rest;
        for (auto v : adj[u]) {
            if (!used[v]) rest.pb(v);
        }

        if (rest.size() >= 2) {
            edges.pb({u, rest[0]});
            edges.pb({u, rest[1]});
        }

        return true;
    }

    return false;

    // int x=-1;
    // int y=-1;
    // for(int i=0;i<n;i++){
    //     if(i==u){
    //         continue;
    //     }

    //     for(auto &v:adj[i]){
    //         if(sub[i]==sub[v]){
    //             continue;
    //         }
    //         if(par[i]==v ){
    //             continue;
    //         }

    //         x=i;
    //         y=v;
    //     }
    // }

    // if(x==-1 && y==-1){
    //     return 0;
    // }

    // yes();
    // // reutrn;
    // vector<pair<int,int>> vec;
    // vec.pb({x,y});

    // while(par[x]!=u){
    //     vec.pb({x,par[x]});
    //     x=par[x];
    // }
    // vec.pb({x, par[x]});

    // while(par[y]!=u){
    //     vec.pb({y,par[y]});
    //     y=par[y];
    // }
    // vec.pb({y, par[y]});

    // int c=0;
    // for(auto v:adj[u]){
    //     if(v==x || v==y){
    //         continue;
    //     // }else{

    //     }

    //     vec.pb({v,u});
    //     c++;
    //     if(c==2){
    //         break;
    //     }
    // }

    // cout<<vec.size()<<endl;
    // for(auto &[a,b]:vec){
    //     cout<<a+1<<" "<<b+1<<endl;
    // }

    // return 1;
}

void solve(){
    int n,m;
    cin>>n>>m;

    vvi adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vi seen(n);
    vi par(n);
    vi sub(n);
    queue<int>q;
    edges.clear();

    for(int i=0;i<n;i++){
        if(adj[i].size()<4){
            continue;
        }
        if(func(adj,i,n,seen,par,sub,q)){
            break;
            // return;
        }
    }
    if(edges.empty()){
        no();
    }else{
        yes();
        cout<<edges.size()<<endl;
        for(auto& [a,b]:edges){
            cout<<a+1<<" " <<b+1<<endl;
        }
    }
    return ;
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