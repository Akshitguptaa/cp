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

vector<bool> sieve(int n) { vector<bool> prime(n+1,true); for (int p = 2; p * p <= n; p++) { if (prime[p] == true) { for (int i = p * p; i <= n; i += p) prime[i] = false; } } return prime;} 

// utitily
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

vector<pair<int, int>> generate_pythagorean_triplets(int limit) {
    vector<pair<int, int>> triplets;
    
    for (int m = 2; m * m <= limit; ++m) {
        for (int n = 1; n < m; ++n) {
            // Only consider the triplet when m and n are coprime and not both odd
            if ((m - n) % 2 == 1 && gcd(m, n) == 1) {
                // Generate a primitive Pythagorean triplet
                int a = m * m - n * n;
                int b = 2 * m * n;
                int c = m * m + n * n;
                // Add to the list of triplets
                if (c <= limit) {
                    triplets.push_back({a, b});
                }
            }
        }
    }
    
    return triplets;
}


void solve(){
    int n;
    cin >> n;
    
    // Special cases where it's impossible to satisfy the conditions
    if (n == 1 || n == 3) {
        cout << -1 << endl;
        return ;
    }

    // For odd n, we directly return -1 because it's impossible to create pairs
    if (n % 2 == 1) {
        cout << -1 << endl;
        return ;
    }

    // Generate Pythagorean triplets up to n
    vector<pair<int, int>> triplets = generate_pythagorean_triplets(n);

    // We will use these triplets to construct the answer
    vector<int> result(n, 0);
    int current_filling = 1;

    for (auto& triplet : triplets) {
        int dist = triplet.first;  // distance to place identical fillings
        for (int i = 0; i + dist <= n; i++) {
            // Check if we can fill positions i and i + dist with the same filling
            if (result[i] == 0 && result[i + dist] == 0) {
                result[i] = result[i + dist] = current_filling;
                current_filling++;
            }
        }
    }

    // If there are any positions left unfilled, it's impossible to satisfy the conditions
    for (int i = 0; i < n; i++) {
        if (result[i] == 0) {
            cout << -1 << endl;
            return ;
        }
    }

    // Output the resulting filling arrangement
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
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