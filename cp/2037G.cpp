//// AKSHIT - template ////

#include <bits/stdc++.h>
#include<chrono>
#include<unordered_set>

using namespace std;
typedef long long int int64;
typedef unsigned long long int uint64;

#define int long long
#define endl "\n"
#define INF LLONG_MAX
#define MOD 998244353
#define PI 3.1415926535897932384626433832795

const int MAX_A = 1e6 + 1;
const int MAX_N = 2e5 + 1;

vector<int> spf(MAX_A); 

int gcd(int a,int b) { if (b==0) return a; return gcd(b, a%b); }
int lcm(int a,int b) { return a/gcd(a,b)*b; }
int power_mod(int a, int b, int mod) { int res = 1; a %= mod; while(b>0) {if (b & 1) res = res * a % mod;a = a * a % mod; b >>= 1;} return res;}
bool prime(int a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
int mod_mul(int a, int b, int m) {return (a%m * b%m)%m;}
int mod_expo(int a, int b, int m){ if(b==0) return 1; int res=mod_expo(a,b/2,m); res=mod_mul(res,res,m); if(b%2==1) res=mod_mul(res,a,m);return res;}
int mod_inv(int a, int m) {return mod_expo(a,m-2,m);}//fermat's theorem
int mod_div(int a, int b, int m) {return mod_mul(a,mod_inv(b,m),m);}
void sieve() {iota(spf.begin(), spf.end(), 0);for (int i = 2; i * i <= MAX_A; ++i) {if (spf[i] == i) { for (int j = i * i; j < MAX_A; j += i) {if (spf[j] == j) {spf[j] = i;}}}}}
vector<int> get_divisors(int x) {set<int> divisors;while (x > 1) {int p = spf[x];divisors.insert(p);while (x % p == 0) x /= p;}vector<int> result(divisors.begin(), divisors.end());return result;}

using vi = vector<int>;
using vb = vector<bool>;
using v32 = vector<int32_t>;
template <class T>
void debug(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }
template <class T>
void inp(vector<T> &v) { for(int i=0;i<v.size();i++) cin>>v[i];}
template <class T>
void display(vector<T> &v) {  for (auto x : v) cout << x << " "; cout << endl; }

int get_divisor_bitmask(int x) {
    vector<int> divisors = get_divisors(x);
    int bitmask = 0;
    for (int d : divisors) {
        bitmask |= (1 << d);
    }
    return bitmask;
}

void solve() {
    int n;
    cin>>n;
    vi a(n);
    inp(a);
    vi v1(n,0); 
    unordered_map<int, int> mp;
    vector<vector<int>> divisors(n);
    vector<int> bitmasks(n);

    for(int i=0; i<n;i++){
        divisors[i]=get_divisors(a[i]);
        bitmasks[i] = get_divisor_bitmask(a[i]);
    }

    v1[0]=1;
    // for (int i=0;i<n;i++){
    //     vi v=get_divisors(a[i]);
    //     for(int j = i+1; j<n; j++){
    //         vi next = get_divisors(a[j]);
    //         unordered_set<int> s(next.begin(),next.end());
    //         int f=0;
    //         for(int i:v){
    //             if(s.count(i)){
    //                 f=1;
    //                 break;
    //             }
    //         }
    //         if(f){
    //             v1[j]=(v1[j]+v1[i])%MOD;
    //         }
    //     }
    // }

    for (int i=0; i<n;i++){
        unordered_set<int> s(divisors[i].begin(),divisors[i].end());
        for(int j=i+1;j<n;j++){
            if(bitmasks[i]&bitmasks[j]) {
                v1[j]=(v1[j]+v1[i])%MOD;
            }
        }
    }
    
    cout<<v1[n-1]<<endl;
}
void solve2(){}

int32_t main(){
    auto begin = chrono::high_resolution_clock::now();
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    sieve();
    // int t;
    // cin >> t;
    // while(t--){
        solve();
        // solve2();
    // }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}