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
    int n,m,v;
    cin>>n>>m>>v;
    vi v1(n);
    inp(v1);
    vi pr(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pr[i + 1] = pr[i] + v1[i];
    }

    vi front(m + 1, INF);
    vi end(m + 1, -1);
    front[0] = 0;
    end[0] = -1;

    int l = 0;
    int sum = 0;
    for (int k = 1; k <= m; k++) {
        if (l >= n) {
            front[k] = INF;
            end[k] = n;
            continue;
        }
        int r = l;
        sum = 0;
        while (r < n && sum < v) {
            sum += v[r];
            r++;
        }
        if (sum >= v) {
            front[k] = front[k - 1] + sum;
            end[k] = r - 1;
            l = r;
        } else {
            front[k] = INF;
            end[k] = n;
        }
    }

    // Assign from the end
    vi sum_end(m + 1, INF);
    vi first_start(m + 1, n);
    sum_end[0] = 0;
    first_start[0] = n;

    int r = n - 1;
    sum = 0;
    for (int k = 1; k <= m; k++) {
        if (r < 0) {
            sum_end[k] = INF;
            first_start[k] = -1;
            continue;
        }
        int l = r;
        sum = 0;
        while (l >= 0 && sum < v) {
            sum += v[l];
            l--;
        }
        if (sum >= v) {
            sum_end[k] = sum_end[k - 1] + sum;
            first_start[k] = l + 1;
            r = l;
        } else {
            sum_end[k] = INF;
            first_start[k] = -1;
        }
    }

    long long S = pr[n];
    long long c = -1;
    for (int k = 0; k <= m; k++) {
        if (front[k] < INF && sum_end[m - k] < INF) {
            if (k == 0 || m - k == 0 || end[k] < first_start[m - k]) {
                long long sum_assigned = front[k] + sum_end[m - k];
                c = max(c, S - sum_assigned);
            }
        }
    }
    if(c>=0){
        cout<<c<<endl;
    }else{
        cout<<-1<<endl;
    }
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
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}