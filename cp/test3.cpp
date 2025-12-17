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

int r,c,m,n,k;
int ans = 0;
vector<string> g;
map<char, int> mp;

int vis[105][105];
int itr = 0;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int bfs(int i,int j,char val){
    if(!(i >= 0 && i < r && j >= 0 && j < c)){
        return 0;
    }

    if(g[i][j] != val){
        return 0;
    }

    int cnt=0;
    queue<pii> q;
    q.push({i, j});
    
    g[i][j] = '.';
    cnt++;
    
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        
        for(int nx=x-1; nx<=x+1;nx++){
            for(int ny= y-1; ny<=y+1;ny++){
                
                if(nx==x && ny==y){
                    continue;
                }
                if(nx>=0 && nx<r && ny>=0 && ny<c && g[nx][ny] == val){
                    cnt++;
                    g[nx][ny]= '.';
                    q.push({nx,ny});
                }
            }
        }
    }
    return cnt;
}

int func() {
    itr++;
    queue<pii> q;

    for(int j=0; j<c; j++){
        if(g[r-1][j] != '.'){
            vis[r-1][j] =itr;
            q.push({r-1, j});
        }
    }
    int cnt=0;



    while(!q.empty()){
        auto [x,y] = q.front(); 
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y + dy[i];

            if(nx>=0 && nx<r && ny>=0 && ny<c ){
                if(g[nx][ny] != '.' && vis[nx][ny]!= itr){

                    if(dy[i] == 0 || g[nx][ny] == g[x][y]){
                        vis[nx][ny] = itr;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){

            if(g[i][j] != '.' && vis[i][j] != itr){

                ans += mp[g[i][j]];
                cnt++;
                g[i][j] = '.';
            }
        }
    }
    return cnt;
}

void solve(){
    cin>>r>>c;
    cin>>m;

    g= vector<string>(r,string(c,'.'));
    int tot=0;    

    for(int i=0; i<m; i++){
        for(int j=0; j<c; j++){

            char ch;
            cin >> ch;
            g[r-1-i][j] = ch;
            if(ch!='.'){
                tot++;
            }
        }
    }

    string s; 
    getline(cin,s);
    getline(cin,s); 
    stringstream ss(s);
    
    vector<char> ky;
    char kc;
    while(ss >> kc){
        ky.pb(kc);
    }

    getline(cin, s); 
    stringstream ss2(s);

    int val;
    int idx = 0;

    while(ss2 >> val && idx< (int)ky.size()){
        mp[ky[idx++]] = val;
    }

    cin>>n>>k;
    
    int cr=0, cc=n, vr=1, vc= -1, b= 0;
    int maxx=0;

    while(b<k && tot){
        if(maxx++>6000){
            break;
        }
        int nr= cr+vr;
        int nc= cc+ vc;
        
        if(nr>=r || nr< 0){
            vr= -vr; 
            continue; 
        }

        if(nc >=c || nc< 0){
            vc= -vc; 
            continue; 
        }
        
        bool h = (cr >= 0 && cr < r && nc >= 0 && nc < c && g[cr][nc] != '.');
        bool v = (nr >= 0 && nr < r && cc >= 0 && cc < c && g[nr][cc] != '.');
        bool d = (nr >= 0 && nr < r && nc >= 0 && nc < c && g[nr][nc] != '.');
        
        if(!h && !v && !d){
            cr = nr; 
            cc = nc; 
            continue;

        }
        
        b++;
        maxx=0;


        if(h && v){
            tot-=bfs(cr, nc, g[cr][nc]);
            
            if(g[nr][cc] != '.'){
                tot-=bfs(nr, cc, g[nr][cc]);
            }
            vr= -vr; 
            vc = -vc;
            tot-=func();
        }else if(h){
            tot-=bfs(cr, nc, g[cr][nc]);
            vc = -vc;
            tot-=func();

        }else if(v){
            tot-=bfs(nr,cc,g[nr][cc]);
            vr = -vr;
            tot-=func();

        }else{
            tot-=bfs(nr, nc, g[nr][nc]);
            vr = -vr; 
            vc = -vc;
            // tot-=func();

        }
    }
    cout<<ans;
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