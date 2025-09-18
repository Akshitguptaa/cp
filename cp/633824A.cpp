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
template <class T>
void debug(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }
template <class T>
void inp(vector<T> &v) { int n=v.size();for(int i=0;i<n;i++) cin>>v[i];}
template <class T>
void display(vector<T> &v) {  for (auto x : v) cout << x << " "; cout << endl; }

// utitily
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// Fenwick Tree
class FenwickTree {
public:
    vector<int> bit;
    int N;

    FenwickTree(int size) {
        N = size;
        bit.resize(N + 1, 0);
    }

    void update(int k, int val) {
        while (k <= N) {
            bit[k] += val;
            k += (k & (-k));
        }
    }

    int query(int k) {
        int res = 0;
        while (k > 0) {
            res += bit[k];
            k -= (k & (-k));
        }
        return res;
    }
};

void solve(){
    int n,q;
    cin>>n>>q;

    FenwickTree fen(q+3);

    vvi vec(q+1);
    set<int> st;
    for(int i=1;i<=q;i++){
        int k;
        cin>>k;
        
        st.insert(i);
        while(k--){
            int x;
            cin>>x;
            vec[i].pb(x);
        }
    }
    
    st.insert(q + 1); 
    
    vector<int> v(all(st));

    unordered_map<int,unordered_set<int>> mp;

    for(int i=1;i<=n;i++){
        mp[0].insert(i);
    }

    vi score(n+1,0);
    vi rank(n+1,0);

    int prev=1;
    for(auto i:v){
        int week = i-prev;

        if(week>0){
            fen.update(1,week);
            fen.update(q+2,-week);

            for(auto [x,y]:mp){
                if(x){
                    int val= y.size()* week;
                    // update for neew 
                    fen.update(1,val);
                    fen.update(x+1,-val);
                }
            }
        }
        if(i<=q){
            for(int j:vec[i]){
                int old_s= score[j];
                int new_s= old_s + 1;

                int old_bonus =fen.query(old_s + 1);
                int new_bonus =fen.query(new_s + 1);

                rank[j]+=old_bonus;
                rank[j]-=new_bonus;

                score[j]= new_s;
                
                mp[old_s].erase(j);
                if (mp[old_s].empty()) {
                    mp.erase(old_s);
                }
                mp[new_s].insert(j);
            }
        }
        prev = i;
    }

    for(int i=1;i<=n;i++){
        int s= score[i];
        rank[i]+= fen.query(s+1);
    }

    for(int i=1;i<=n;i++){
        cout<<fixed<<setprecision(10)<<(long double)rank[i]/q<<endl;
    }
}

void solve2(){}

int32_t main(){
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    int t;
    // cin >> t;
    t=1;
    while(t--){
        solve();
        // solve2();
    }

}

//END