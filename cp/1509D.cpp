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
template <class T>
void debug(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }
template <class T>
void inp(vector<T> &v) { int n=v.size();for(int i=0;i<n;i++) cin>>v[i];}
template <class T>
void display(vector<T> &v) {  for (auto x : v) cout << x << " "; cout << endl; }

// utitily
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

string findLCS(string& s1,string& s2) {
    int n=s1.size();
    int m=s2.size();
    vi prev(m+1,0);
    vi curr(m+1,0);

    // space optimised lcs
    for(int i=1; i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                curr[j]=1+prev[j-1];
            }else{
                curr[j] = max(prev[j], curr[j-1]);
            }
        }
        swap(prev, curr);
    }

    // lcs from dp table 
    string lcs = "";
    int i=n,j=m;
    vvi dp(2, vi(m+1, 0));
    for(int ii=1; ii<=n;ii++){
        for(int jj=1; jj<=m; jj++) {
            if(s1[ii-1]==s2[jj-1]){
                dp[ii%2][jj]=1+dp[(ii-1)%2][jj-1];
            }
            else{
                dp[ii%2][jj]=max(dp[(ii-1)%2][jj], dp[ii%2][jj-1]);
            }
        }
    }
    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            lcs+=s1[i-1];
            i--; j--;
        }else if(dp[(i-1)%2][j] > dp[i%2][j-1]){
            i--;
        }else{
            j--;
        }
    }
    reverse(all(lcs));
    return lcs;
}

string func(string s1,string s2){
    string lcs=findLCS(s1, s2);
    string str="";

    int i=0,j=0,k=0;
    int n= lcs.size();
    while(k<n){
        while(i<s1.size() && s1[i]!=lcs[k]){
            str+=s1[i];
            i++;
        }
        while(j<s2.length() && s2[j]!=lcs[k]) {
            str+=s2[j];
            j++;
        }
        str+=lcs[k];
        i++;
        j++;
        k++;
    }

    str+=s1.substr(i)+s2.substr(j);
    return str;
}

void solve(){
    int n;
    cin>>n;
    string a,b,c;
    cin>>a>>b>>c;



    string s1= func(a,b);
    string s2= func(b,c);
    string s3= func(a,c);

    if(s1.size()<=3*n){
        cout<<s1<<endl;
        return ;
    }
    if(s2.size()<=3*n){
        cout<<s2<<endl;
        return ;
    }
    if(s3.size()<=3*n){
        cout<<s3<<endl;
        return ;
    }
}

void solve2(){}

int32_t main(){
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        solve();
        // solve2();
    }

}

//END