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
vb si= sieve(100);
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

int n,s,l,m,k,p;
int spline,ports;
int tot;

struct Link{
    int oxc,spx,lkx, spy, lky;
};

void func1(int loc,int oxc,int& sp,int& lk){

    int plane= oxc/(m/p); 
    int base=plane*spline;
    sp= base+(loc/k);
    lk=loc%k;
}

using vppii= vector<pair<pii,int>> ;
using ppii =pair<pii,int>;

void func(int q) {
    // map<pii,int> req(q);
    vppii reqs(q);
    
    map<pii,int> cnt;

    for(int i=0;i<q;i++){
        int u,v,a,b;
        cin>>u>>a>>v>>b;
        
        reqs[i] = {{u,v},i};
        if(u>v){
            swap(u,v);
        }
        cnt[{u,v}]++;
    }

    vector<pair<int,pii>> temp;
    for(auto [a,b]:cnt){
        temp.pb({b,a});
    }
    sort(rall(temp));

    vvi vec(m,vi(tot,-1));
    vvi used(m,vi(n,0));
    map<pii,vector<Link>> routes;

    // /pehle ek link de 
    for(auto& [a,b]:cnt){
        auto [u,v]= a;
        
        for(int i=0; i<m;i++){
            if(routes[{u,v}].empty()){

                if(used[i][u]<ports && used[i][v]<ports){
                    int pu=u*ports+used[i][u];
                    int pv=v*ports+used[i][v];
                    
                    vec[i][pu]= pv;
                    vec[i][pv]= pu;

                    Link lnk;
                    lnk.oxc = i;
                    func1(used[i][u],i,lnk.spx,lnk.lkx);
                    func1(used[i][v],i,lnk.spy,lnk.lky);
                    
                    routes[{u,v}].pb(lnk);
                    
                    used[i][u]++;
                    used[i][v]++;
                    
                    break;
                }
            }
        }
    }

    for(auto& [a,b]:temp) {
        auto [u,v]= b;

        
        for(int i=0; i<m;i++){
            while(used[i][u]<ports && used[i][v]<ports){
                int pu=u*ports+used[i][u];
                int pv=v*ports+used[i][v];
                
                vec[i][pu]= pv;
                vec[i][pv]= pu;

                Link lnk;
                lnk.oxc = i;
                func1(used[i][u],i,lnk.spx,lnk.lkx);
                func1(used[i][v],i,lnk.spy,lnk.lky);
                
                routes[{u,v}].pb(lnk);
                
                used[i][u]++;
                used[i][v]++;
            }
        }
    }

    for(int i=0; i<m;i++){
        for(int j=0;j<tot;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<q;i++){

        auto [u,v]= reqs[i].first;
        // bool f=0;
        
        int minn=min(u,v);
        int maxx= max(u,v);

        auto links= routes[{minn,maxx}];
        int sz= links.size();
        
        if(!links.empty()){
            auto l= links[i%sz];
            
            if(u==minn){
                cout<<l.spx<<" "<<l.lkx<<" "<<l.oxc<<" " <<l.spy<<" "<< l.lky <<endl;
            }else{
                cout<<l.spy<<" "<<l.lky<<" "<<l.oxc << " " <<l.spx<<" "<< l.lkx << endl;
            }
            continue;
        }
        cout<<"0 0 0 0 0"<<endl;
    }

    
}

void solve(){
    cin>>n>>s>>l>>m>>k>>p;

    spline= s/p;
    ports= spline*k;
    tot= n*ports;

    
    for(int i=0;i<5;i++){
        int q;cin>>q;
        func(q);
    }
}

void solve2(){}

int32_t main(){
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    int t;
    // cin >> t;
    t=1;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
        // solve2();
    }

}