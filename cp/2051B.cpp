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
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

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
void inp(vector<T> &v) { for(int i=0;i<v.size();i++) cin>>v[i];}
template <class T>
void display(vector<T> &v) {  for (auto x : v) cout << x << " "; cout << endl; }

// utitily
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

void solve(){
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    // int l=1;
    int x=a+b+c;
    // int r=3*(n+x)/(x);
    int full=n/x;
    int rem=n%x;
    if (rem == 0) {
        cout << full * 3 << endl;
    } else {
        int s = 0;
        for (int i = 1; i <= 3; i++) {
            if (i == 1) s += a;
            else if (i == 2) s +=  b;
            else s += c;

            if (s >= rem) {
                cout << full * 3 + i << endl;
                break;
            }
        }
    }
    // int ans=r;
    // if(a==b&& b==c && a==c){
    //     cout<<n<<endl;
    //     return;
    // }
    // while(l<=r){
    //     int mid=r+(l-r)/2;
    //     int full= mid/3;
    //     int rem=mid%3;
    //     int dis=full*(x);
    //     if(rem==1){
    //         dis+=a;
    //     }else if(rem==2){
    //         dis+=a+b;
    //     }else{
    //         dis+=a+b+c;
    //     }

    //     if(dis>=n){
    //         ans=mid;
    //         r=mid-1;
    //     }else{
    //         l=mid+1;
    //     }
    // }
    // cout<<ans<<endl;
}

void solve2(){}

int32_t main(){
    auto begin = chrono::high_resolution_clock::now();
    vector<bool> v= sieve(1000);
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