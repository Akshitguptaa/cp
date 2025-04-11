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
vector<bool> s= sieve(100);

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

void solve(){
    int n;
    cin>>n;
     vi v(n);
     inp(v);

    vi v1(n);
    inp(v1);
    // if(v1==v){
    //     cout<<-1<<endl;
    //     return;
    // }
    for (int i = 0; i < n; i++) {
        v[i]--;
        v1[i]--;
    }

    int c=0;
    for(int i=0;i<n;i++){
        if(v[i]==v1[i]){
            c++;
        }
    }
    if(n&1){
        if(c!=1){
            cout<<-1<<endl;
            return;
        }
    }else{
        if(c>0){
            cout<<-1<<endl;
            return;
        }
    }


    vi temp1= v1;
    reverse(all(temp1));
    if(temp1==v){
        cout<<0<<endl;
        return;
    }     
    
    vector<int> p(n), ia(n);
    for (int i = 0; i < n; i++) {
        ia[v[i]] = i;
        p[v[i]] = v1[i];
    }

    vector<int> ulta(n);
    for (int i = 0; i < n; i++) {
        ulta[v1[i]] = v[i];
    }
    for (int i = 0; i < n; i++) {
        if (v[i] != ulta[p[v[i]]]) {
            cout << -1 << endl;
            return;
        }
    }

    // edge case khatam 

    
    vector<int> q(n, -1);
    vector<bool> used(n, false);
    int l = 0, r = n - 1;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        if (p[i] == i) {
            q[ia[i]] = n / 2;
            used[n / 2] = true;
            visited[i] = true;
        } else if (p[i] != i && !visited[p[i]]) {
            while (l < r && used[l]) l++;
            while (l < r && used[r]) r--;
            if (l >= r) break;  
            q[ia[i]] = l;
            q[ia[p[i]]] = r;
            used[l] = used[r] = true;
            visited[i] = visited[p[i]] = true;
            l++;
            r--;
        }
    }
   for (int i = 0; i < n; i++) {
        if (q[i] == -1) {
            while (used[l]) l++;
            q[i] = l;
            used[l] = true;
            l++;
        }
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        int iter = 0;
        while (q[i] != i && iter < n) {
            if (q[i] < 0 || q[i] >= n) {
                cout << -1 << endl;
                return;
            }
            ans.push_back({i + 1, q[i] + 1});
            swap(v[i], v[q[i]]);
            swap(v1[i], v1[q[i]]);
            swap(q[i], q[q[i]]);
            swap(ia[v[i]], ia[v[q[i]]]);
            p[v[i]] = v1[i];
            p[v[q[i]]] = v1[q[i]];
            iter++;
        }
        if (iter >= n) {
            cout << -1 << endl;
            return;
        }
    }

    // if(n&1){
    //     int idx= -1;
    //     // int idx1= 
    //     for(int i=0;i<n;i++){
    //         if(v[i]==v1[i]){
    //             idx= i+1;
                
    //         }
    //     }
    //     swap(v[idx-1],v[(n+1)/2-1]);
    //     swap(v1[idx-1],v1[(n+1)/2-1]);
    //     ans.pb({idx,(n+1)/2});
    // }
    
    for(int i=0; i<n;i++) {
        if(v[i]!=v1[n-1-i]) {
            // cout<<"last case"<<endl;
            // cout<<v[i]<<v1[n-1-1]<<endl;
            cout<<"-1"<<endl;
            return;
        }
    } 
    int sz= ans.size();
    // if(ans.size()%2==0){
    // }

    cout<<sz<<endl;
    for(auto [x,y]:ans){
        cout<<x << " "<<y<<endl;
    }
    return;

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