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

const int M= 998244353; 
vi fact,ifact,power(300005,1);
void prec(int maxx=1e6) {
    for(int i=1;i<=300000;i++){
        power[i]= mod_mul(2,power[i-1],M);
    }

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

void solve(){
    int n,m;
    cin>>n>>m;

    vi mp(300,0);
    vb bt(62,0);
    for(int i=0;i<n;i++){
        int x; cin>>x;
        mp[x]++;
        bt[x]=1;
    }
    
    for(int i=0;i<m;i++){
        int q,x; cin>>q>>x;
        
        if(q==1){
            vector<vvi> vec;
            bt[x]=1;
            n++;
            mp[x]++;
        }
        if(q==2){
            mp[x]--;
            n--;
            if(!mp[x]){
                bt[x]=0;
            }
        }
        // 1 1 0 0 0 0 0 
        // 1 1 0 0 1 0 1
        if(q==3){
            int ans=0;
            vi mp1= mp;
            vi pre= mp1;
            for(int i=1;i<=61;i++){
                pre[i]+=pre[i-1];
            }
            int cnt=0;
            int temp=1;
            int f=1;
            for(int i=61;i>=0;i--){
                int avail =mp[i+cnt];
                if(x&(1LL<<i)){
                    if(avail){
                        temp = mod_mul(avail,temp,M);
                        mp1[temp]--;  
                    }else{
                        f=0;
                        break;
                    }
                    // cout<<i<<" "<<mp[i]<<" "<<(x&(1LL<<i))<<endl;
                        // cout<<"h"<<endl;
                }else{
                    if(avail){
                        temp= mod_mul(avail,temp,M);
                        temp= (temp*power[n-cnt-1])%M;
                        ans= (ans+temp)%M;
                    }


                    // if(bt[i]){
                    //     q.push({mp[i],i});
                    // }
                }
            }
            if(f){
                int x=0;
                for(int i=0;i<=60;i++){
                    x += mp1[i];
                }
                
                ans= (ans+mod_mul(temp,power[x],M))%M;
            }

            cout<<ans<<endl;

        }
    }
}

void solve2(){}

int32_t main(){
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    prec();
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
        // solve2();
    }

}