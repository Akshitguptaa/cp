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

void dfs(vector<vector<int>>& graph,vector<bool>& v,int n){
    v[n]=1;
    for(int i:graph[n]){
        if(!v[i]){
            dfs(graph,v,i);
        }
    }
}

pair<int,int> maxi(vector<int>& v) {
    int maxx=0;
    int maxx1=0;
    for(int i=1;i<v.size();i++){
        if (v[i] > v[maxx]) {
            maxx = i;
        }
    }
    for(int i=1;i<v.size();i++){
        if (i != maxx && (maxx1 == -1 || v[i] > v[maxx1])){
            maxx1=i;
        }
    }
    
    return {maxx,maxx1};


}


bool compare(int a,int b,vector<int>& v) {
    if (v[a]!=v[b]) {
        return v[a]>v[b];
    }
    return a<b;
}

int func(int n,vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(n+1);
    vector<int> degree(n+1,0);
    
    for (auto& i:edges) {
        int u=i.first;
        int v=i.second;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    
    // auto[maxx,maxx1]=maxi(degree);

    vi v(n+1);
    rep(i,0,n){
        v[i]=i+1;
    }

    sort(all(v), [&](int a,int b) {return compare(a,b,degree);});

    for (int i = 1; i <= n; i++) {
    sort(all(graph[i]));
}

//     int maxx = -1, maxx1 = -1;
//     int val = -1, val1 = -1;
    
//     for (int i = 1; i <= n; i++) {
//         if (degree[i] > maxx) {
//             maxx1 = maxx;
//             val1 = val;
//             maxx = degree[i];
//             val = i;
//         } else if (degree[i] > maxx1) {
//             maxx1 = degree[i];
//             val1 = i;
//         }
//     }

//    bool f=0;
//     for(int i:graph[val]) {
//         if(i==val1) {
//             f=1;
//             break;
//         }
//     }

    // vector<vector<int>> temp(n + 1);
    // for (int i = 1; i<=n;i++) {
    //     if (i != maxx && i!=maxx1) {
    //         for (int j: graph[i]) {
    //             if (j != maxx && j!=maxx1) {
    //                 temp[i].push_back(j);
    //             }
    //         }
    //     }
    // }

    int maxi=0;
    rep(i,0,n){
        int u=v[i];
        for (int j = i+1; j< n;j++) {
            int temp = v[j];
            bool f1 = binary_search(all(graph[u]), temp);
            if (!f1) {
                int temp_degree = degree[u] + degree[temp] - 1;
                maxi = max(maxi, temp_degree);
                break;
            }
        }
    }


    int maxi1=0;
    for (int i=1;i<=n;i++){
        for (auto j:graph[i]){ 
            if(i<j){ 
                int temp = (int)degree[i] +degree[j] - 2;
                maxi1 = max(maxi1,temp);
            }
        }
    }

    // vector<bool> v(n+1,0);
    // int c=0;
    // v[val]=1;
    // v[val1]=1;

    // for(int i=1; i<=n;i++){
    //     if(!v[i]){
    //         c++;
    //         // dfs(graph,v,i);
    //     }
    // }
    // if(f){
    //     c--;
    // }

    return max(maxi,maxi1);
}

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> v(n-1);
    
    for(int i=0;i<n-1;i++){
        cin>>v[i].first>>v[i].second;
    }

    int ans = func(n, v);
    cout << ans << endl;
}

void solve2(){}

int32_t main(){
    auto begin = chrono::high_resolution_clock::now();
    vector<bool> s= sieve(100);
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