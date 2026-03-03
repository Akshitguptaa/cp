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
vb s= sieve(100);
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

vi spf(int n){ vi ans(n+1); for(int i=0 ;i<=n ;i++)ans[i]=i; for(int i=2 ;i*i<=n ;i++) if(ans[i]==i) for(int j=i*i ; j<=n ;j+=i) if(ans[j]==j) ans[j]=i ; return ans;}

void solve(){
    int n,m;cin>>n>>m;

    vi v(n);
    vi v1(m);
    inp(v);inp(v1);
    int maxx= n+m;

    vi prime= spf(maxx);

    set<int> st(all(v));
    vi vec(maxx+2,0);

    for(auto i:st){
        for(int j=i;j<=maxx;){
            vec[j]++;
            j+=i;
        }
    }
    
    vi temp(maxx+2,0);
    for(auto i:st){
        while(i>1){
            int val= prime[i];
            int c=0;
            while(i%val==0){
                i/=val;
                c++;
            }
            
            temp[val] = max(temp[val],c);
        }
    }
    
    int val = 1;
    for(int i=2;i<=maxx;i++){
        while(temp[i]){
            val*=i;
            temp[i]--;
            
            if(val>maxx){
                break;
            }
        }
        
        if(val>maxx){
            break;
        }
    }
    
    int cnt=0;
    for(auto i:v1){
        if(vec[i]){
            cnt++;
        }
    }

    int cnt1=m;
    if(val<=maxx){
        for(auto i:v1){
            if(i%val==0){
                cnt1--;
            }
        }
    }

    if(cnt>cnt1){
        cout<<"Alice"<<endl;
        return ;
    }


    if(cnt<cnt1){
        cout<<"Bob"<<endl;
        return ;
    }
    
    if(m&1){
        cout<<"Alice"<<endl;
        return ;
    }
    cout<<"Bob"<<endl;
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