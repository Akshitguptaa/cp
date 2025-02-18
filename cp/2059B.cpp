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

struct State {
    int pos;
    int blocks;
    State(int p = 0, int b = 0) : pos(p), blocks(b) {}
};

void solve() {
    int n, k;
    cin >> n >> k;
    
    vi a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    
    int r = k / 2;
    
    // Store positions of each value
    unordered_map<int, vi> pos;
    pos.reserve(n * 2);
    rep(i, 1, n + 1) pos[a[i]].pb(i);
    for(auto &p : pos) sort(all(p.second));
    
    // Precompute next different element
    vi next_diff(n + 2, 0);
    next_diff[n] = n;
    rrep(i, 1, n) {
        next_diff[i] = (a[i] == a[i + 1]) ? next_diff[i + 1] : i;
    }
    
    // Binary search for next occurrence
    auto get_next = [&](int start, int val, int UB) -> int {
        if(pos.find(val) == pos.end()) return INF;
        auto &vec = pos[val];
        int lo = 0, hi = vec.size();
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            if(vec[mid] < start) lo = mid + 1;
            else hi = mid;
        }
        return (lo < vec.size() && vec[lo] <= UB) ? vec[lo] : INF;
    };
    
    vector<State> F(n + 2);
    F[0] = State(0, 0);
    
    // Check early sabotage
    int maxStart = n - 2 * (r - 1);
    if(2 <= maxStart) {
        if(a[2] != 1 || next_diff[2] < maxStart) {
            cout << 1 << endl;
            return;
        }
    }
    
    // Check for position 1 mismatch
    int UB_new = n - 2 * (r - 1);
    int candidate = get_next(2, 1, UB_new);
    if(candidate == INF) {
        cout << 1 << endl;
        return;
    }
    F[1] = State(candidate, 1);
    
    // Main DP
    int Mforced = 1;
    int bestSabotage = INF;
    
    rep(i, 1, n + 1) {
        State st = F[i];
        int bestPos = INF, bestBlocks = INF;
        
        if(st.pos + 1 <= n - 2 * (r - st.blocks)) {
            int extPos = st.pos + 1;
            if(extPos <= n && a[extPos] == i + 1) {
                bestPos = extPos;
                bestBlocks = st.blocks;
            }
        }
        
        if(st.blocks < r) {
            UB_new = n - 2 * (r - (st.blocks + 1));
            int cand = get_next(st.pos + 2, i + 1, UB_new);
            if(cand < bestPos) {
                bestPos = cand;
                bestBlocks = st.blocks + 1;
            }
        }
        
        if(bestPos == INF) {
            Mforced = i;
            break;
        }
        
        F[i + 1] = State(bestPos, bestBlocks);
        Mforced = i + 1;
    }
    
    cout << Mforced + 1 << endl;
}

void solve2(){}

int32_t main(){
    auto begin = chrono::high_resolution_clock::now();
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