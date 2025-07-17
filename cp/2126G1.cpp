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

bool func(int midd,int j ,vi &v,vi &vec){
    vi temp;

    // where it is eql
    vi idx;

    for(int i=0;i<vec.size();i++){
        if(v[vec[i]]>=midd){
            temp.pb(1);
        }else{
            temp.pb(-1);
        }

        if(v[vec[i]]==j){
            idx.pb(i);
        }
    }


    int n= temp.size();
    vi pre(n+1,0);

    for(int i=0;i<n;i++){
        pre[i+1] = pre[i]+temp[i];
    }

    vi minn(n+1);
    minn[0]=pre[0];
    for(int i=1;i<=n;i++){
        minn[i] = min(minn[i-1], pre[i]);
    }

    vi maxx(n+2, INT_MIN);
    maxx[n] = pre[n];
    for(int i=n-1;i>=0;i--){
        maxx[i] = max(maxx[i+1],pre[i]);
    }

    for(auto i:idx){
        int l=minn[i];
        int r=maxx[i+1];
        if(r-l>=0){
            return 1;
        }
    }
    return 0;

}

void solve(){
    int n;
    cin>>n;

    vi v(n);
    inp(v);

    int maxx = *max_element(all(v));
    int ans=0;

    for(int i=1;i<=maxx;i++){
        int j=0;
        while(j<n){
            if(v[j]<i){
                j++;
                continue;
            }

            vi vec;
            int f=0;

            int k=j;

            for(k=j;k<n;k++){
                if(v[k]<i){
                    break;
                }
                    if(v[k]==i){
                        f=1;
                    }
                    vec.pb(k);
            }

            if(!f){
                j=k;
                continue;
            }

            int l=i+1;
            int r= maxx;
            int val = i;

            while(l<=r){
                int midd= l+(r-l)/2;

                if(func(midd,i,v,vec)){
                    val= midd;
                    l= midd+1;
                }else{
                    r= midd-1;
                }
            }

            ans = max(ans,val-i);
            j=k;

        }
    }

    cout<<ans<<endl;
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