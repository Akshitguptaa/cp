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
vb s=sieve(100);
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
int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};

vi target;

void func(vi n,vi u,string s, string& res){
    vi r= {u[1]*n[2] - u[2]*n[1], u[2]*n[0] - u[0]*n[2], u[0]*n[1] - u[1]*n[0]};

    if(n[0]+u[0]-r[0] == target[0] && n[1]+u[1]-r[1] == target[1] && n[2]+u[2]-r[2] == target[2]){
        // TL
        res += s[0];

    }else if(n[0]+u[0]+r[0] == target[0] && n[1]+u[1]+r[1] == target[1] && n[2]+u[2]+r[2] == target[2]) {
        // TR
        res += s[1];
    }else if(n[0]-u[0]-r[0] == target[0] && n[1]-u[1]-r[1] == target[1] && n[2]-u[2]-r[2] == target[2]) {
        // BL
        res += s[2];
    }else {

        // BR
        res += s[3];
    }
}

void solve(){
    vector<string> vec(4);
    vpii pos;

    for(int i=0;i<4; i++){
        cin>>vec[i];
        for(int j=0;j<4; j++){

            if(vec[i][j] != '.'){
                pos.pb({i,j});
            }
        }
    }

    string str,query;
    cin>> str>> query;

    map<char,vi> norm, up;
    map<char,string> st;

    int idx=0;
    for(auto &p:pos){

        st[vec[p.first][p.second]] = str.substr(idx, 4);
        idx += 4;
    }

    vector<tuple<int, int, vi, vi>> q;
    vvb vis(4,vb(4,0));

    if(!pos.empty()){

        q.pb({pos[0].first, pos[0].second, {0,0,1}, {0,1,0}});
        vis[pos[0].first][pos[0].second] = 1;
    }


    for(int j=0;j< (int)q.size();j++){
        auto [r,c,n,u] = q[j];

        char id = vec[r][c];
        norm[id] = n;
        up[id] = u;

        for(int i=0; i<4; ++i){
            int r1 = r+dr[i];
            int c1 = c+dc[i];

            if(r1 >= 0 && r1 < 4 && c1 >= 0 && c1 < 4 && vec[r1][c1] != '.' ){
                if(!vis[r1][c1]){

                    vis[r1][c1] = 1;
                    vi nn(3), nu(3);
                    
                    if(i ==0){ //up
                        nn= u;
                        nu= {-n[0], -n[1], -n[2]};
                    }else if(i==1){ // down
                        nn = {-u[0], -u[1], -u[2]};
                        nu = n;
                    }else if(i==2){ // left
                        nn = {n[1]*u[2] - n[2]*u[1], n[2]*u[0] - n[0]*u[2], n[0]*u[1] - n[1]*u[0]};
                        nu = u;
                    }else{ //right
                        nn= {u[1]*n[2] - u[2]*n[1], u[2]*n[0] - u[0]*n[2], u[0]*n[1] - u[1]*n[0]};
                        nu= u;
                    }

                    q.pb({r1,c1,nn,nu});
                }
            }
        }
    }

    target= {0,0,0};
    for(char i:query){
        target[0]+= norm[i][0];
        target[1]+= norm[i][1];
        target[2]+= norm[i][2];
    }

    string res="";
    for(char c: query){
        vi n= norm[c];
        vi u= up[c];
        string s= st[c];
        
        func(n,u,s,res);
    }
    cout<<res;
}

void solve2(){}

int32_t main(){
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
        // solve2();
    }

}