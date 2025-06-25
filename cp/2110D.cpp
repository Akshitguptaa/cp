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
vector<bool>s= sieve(100);

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

// bs ftw
bool func(vector<pair<int,pair<int,int>>> &vec,int wt,vi& v1,int n){
    vi temp(n+1,INT_MIN);
    temp[1]= v1[1];
    

        vector<pair<int,pair<int,int>>> edge;
    for(auto &[w,x]:vec){
            auto [u,v] = x;
            if(w<=wt) {
                edge.pb({w,{u,v}});
            }
        }

    for(int i=0;i<n-1;i++){
        bool f=0;
        for(auto &[w, x]:edge){
            auto [u,v] = x;
            if(temp[u]>=w) {
                int temp1 =temp[u]+v1[v];
                if(temp1>temp[v]){
                    temp[v] = temp1;
                    f=true;
                }
            }
        }
        if (!f) break;
    }

        return temp[n]>=0;
}

void solve(){
    int n,m;
    cin>>n>>m;
    
    vi v1(n+1);
    for(int i=0;i<n;i++){
        cin>>v1[i+1];

    }

    vector<pair<int,pair<int,int>>>vec(m);
    set<int> st;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        // inp
        vec[i]={z,{x,y}};
        st.insert(z);
    }

    vi st1(all(st));
    // sort(all(vec));
    int l=0;
    int r= st1.size()-1;
    int ans=-1;


    // vi temp(n+1,INT_MIN);
    // temp[1]= v1[1];
    // int i=0;
    while(l<=r){
        int mid= l+(r-l)/2;
        int wt= st1[mid];
        if(func(vec,wt,v1,n)){
            ans=wt;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }

    cout<<ans<<endl;
        
    //     for(int j=0;j<n-1;j++){
    //         int f=0;
    //         for(int k=0;k<i;k++){

    //             auto [w,x]=vec[k];
    //             auto [u,v]= x;
    //             if(temp[u]>=w){
    //                 int temp1= temp[u]+v1[v];
    //                 if(temp1>temp[v]){
    //                     temp[v]= temp1;
    //                     f=1;
    //                 }
    //             }
                
    // cout<<ans<<endl;

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