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

void solve(){
    int n,k;
    cin>>n>>k;

    vi v(n);

    vi cnt(n+1,0);

    for(int i=0;i<n;i++){
        cin>>v[i];
        cnt[v[i]]++;
    }

    int s= accumulate(all(v),(int)0);

    if(k==0){
        cout<<s<<endl;
        return ;
    }

    int mexx=n;
    for(int i=0;i<n;i++){
        if(cnt[i]==0){
            mexx=i;
            break;
        }
    } 

    vi vec(n);
    int s1=0;
    for(int i=0;i<n;i++){
        if(cnt[v[i]]==1 && v[i]<mexx){
            vec[i]= v[i];
        }else{
            vec[i]= mexx;
        }
        s1+=vec[i];
    }

    if(k==1){
        cout<<s1<<endl;
        return ;
    }

    vi cnt1(n+1,0);

    for(auto i:vec){
        cnt1[i]++;
    }

    
    int mexi=n;
    for(int i=0;i<n;i++){
        if(cnt1[i]==0){
            mexi=i;
            break;
        }
    }

    vi vec2(n);
    int s2=0;
    for(int i=0;i<n;i++){
        if(cnt1[vec[i]]==1 && vec[i]<mexi){
            vec2[i] = vec[i];
        }else{
            vec2[i]= mexi;
        }
        s2+=vec2[i];
    }
    
    vi cnt2(n+1,0);
    for(auto i:vec2){
        cnt2[i]++;
    }

    int mexi2 = n;
    for(int i=0; i<=n;i++){
        if(cnt2[i]==0){
            mexi2=i;
            break;
        }
    }

    if((k&1)){
        int s3=0;
        for(int i=0; i<n;i++){
            if(cnt2[vec2[i]]==1 && vec2[i]<mexi2){
                s3+=vec2[i];
            }else{
                s3+=mexi2;
            }
        }
        cout<<s3<<endl;
    }else{
        int s2=0;
        for(int i=0;i<n;i++){
            if(cnt1[vec[i]]==1 && vec[i]<mexi){
                s2+=vec[i];
            }else{
                s2+=mexi;
            }
        }
        cout<<s2<<endl;
    }
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
