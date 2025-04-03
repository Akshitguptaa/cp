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

void solve(){
    int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1), c(n + 1);
	for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
	for(int i = 1; i <= n; i++){
        cin>>b[i];
    }
	for(int i = 1; i <= n; i++){
        cin>>c[i];
    }

    int sum= accumulate(all(a),(int)2);
	
	vector<int> prefa(n + 1), prefb(n + 1), prefc(n + 1);
	for(int i = 1; i <= n; i++) prefa[i] = prefa[i - 1] + a[i];
	for(int i = 1; i <= n; i++) prefb[i] = prefb[i - 1] + b[i];
	for(int i = 1; i <= n; i++) prefc[i] = prefc[i - 1] + c[i];
	sum/=3;

	int l=1,l2=1, r2 = 2, l3 = 1, r3 = 2; 
	for(int r = 1; r <= n; r++){
		while(l < r and prefa[r] - prefa[l] >= sum) l++;
		while(l2 < l - 1 and prefb[l - 1] - prefb[l2] >= sum) l2++;
		while(r2 < n and prefb[r2] - prefb[r] < sum) r2++;
		while(l3 < l - 1 and prefc[l - 1] - prefc[l3] >= sum) l3++;
		while(r3 < n and prefc[r3] - prefc[r] < sum) r3++;
		
		if(l > 1 and r < n and prefa[r] - prefa[l - 1] >= sum and prefb[l - 1] >= sum and prefc[n] - prefc[r] >= sum){
			cout << l << ' ' << r << " 1 " << l - 1 << ' ' << r + 1 << ' ' << n << '\n';
			return;
		}
		if(l > 1 and r < n and prefa[r] - prefa[l - 1] >= sum and prefc[l - 1] >= sum and prefb[n] - prefb[r] >= sum){
			cout << l << ' ' << r << ' ' << r + 1 << ' ' << n << " 1 " << l - 1 << '\n';
			return;
		}
		if(l2 > 1 and prefa[r] - prefa[l - 1] >= sum and prefb[l - 1] - prefb[l2 - 1] >= sum and prefc[l2 - 1] >= sum){
			cout << l << ' ' << r << ' ' << l2 << ' ' << l - 1 << ' ' << 1 << ' ' << l2 - 1 << '\n';
			return;
		}
		if(r2 < n and prefa[r] - prefa[l - 1] >= sum and prefb[r2] - prefb[r] >= sum and prefc[n] - prefc[r2] >= sum){
			cout << l << ' ' << r << ' ' << r + 1 << ' ' << r2 << ' ' << r2 + 1 << ' ' << n << '\n';
			return;
		}
		if(l3 > 1 and prefa[r] - prefa[l - 1] >= sum and prefc[l - 1] - prefc[l3 - 1] >= sum and prefb[l3 - 1] >= sum){
			cout << l << ' ' << r << ' ' << 1 << ' ' << l3 - 1 << ' ' << l3 << ' ' << l - 1 << '\n';
			return;
		}
		if(r3 < n and prefa[r] - prefa[l - 1] >= sum and prefc[r3] - prefc[r] >= sum and prefb[n] - prefb[r3] >= sum){
			cout << l << ' ' << r << ' ' << r3 + 1 << ' ' << n << ' ' << r + 1 << ' ' << r3 << '\n';
			return;
		}
	}
	cout << "-1\n";
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