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
#define vvi vector<vector<int>>

void func1(int i,int x){
    if(i==0){
        
    }
}

void solve(){
    int n,k;
    cin>>n>>k;
    vi v(n);
    inp(v);
    
    // vector<pair<int,int>> vec;
    // for(int i=0;i<n;i++){
    //     vec.pb({v[i],i});
    // }

    // vvi memo(n+1,vi(k+1,-1));
    int ans=INT_MIN;

    vvi l(n+1);
    // vvi r(n+1);
    l[0]=vi();
    // r[n]=vi();

    for(int i=0;i<n;i++){
        l[i+1]=l[i];
        l[i+1].pb(v[i]);
        sort(rall(l[i+1]));

        if(l[i+1].size()>k){
            l[i+1].resize(k);
        }
    }
    // for(int i=n-1;i>=0;i--){
    //     r[i]=r[i+1];
    //     r[i].pb(v[i]);
    //     sort(rall(r[i]));

    //     if(r[i].size()>k){
    //         r[i].resize(k);
    //     }
    // }

    vvi memo1(n+1,vi(k+1,0));
    // vvi memo2(n+1,vi(k+1,0));
    for(int i=0;i<=n;i++){
        for(int x=1;x<=k;x++){
            if(x>=l[i].size()+1){
                break;
            }
            memo1[i][x]=memo1[i][x-1]+l[i][x-1];
        }
        // for(int x=1;x<=k;x++){
        //     if(x>=r[i].size()+1){
        //         break;
        //     }
        //     memo2[i][x]=memo2[i][x-1]+r[i][x-1];
        // }
    }

    for(int j=0; j<n; j++){
        int n1=j;
        int n2=n-j-1;

        if(j==0){
            if(n2>=k){
                vi r;
                rep(i,j+1,n){
                    r.pb(v[i]);
                }
                sort(rall(r));
                int sum=v[0];
                rep(i,0,k){
                    sum+=r[i];
                }
                ans=max(sum,ans);
            }
            continue;
        }

        if(j==n-1){
            if(n1>=k){
                int sum=v[n-1]+memo1[j][k];
                ans=max(sum,ans);
            }
            continue;
        }
        // vi l, r;
        // for(int i=0; i<j; i++){
        //     l.pb(v[i]);
        // }
        // for(int i=j+1; i<n; i++){
        //     r.pb(v[i]);
        // }
        
        // for(int i=0; i<r.size();i++){
        //     if(vec.size()>=k){
        //         break;
        //     }

        //     if(i>=k){
        //         break;
        //     }
        //     vec.push_back(r[i]);
        // }
        if((n1+n2)<k || n1<1 || n2<1){
            continue;
        }

        int temp=max((int)1,k-n2);
        for(int a=temp; a<=n1; a++){
            if(a>=k){
                break;
            }
            int r1=k-a;
            if(r1>n2){
                continue;
            }
            vi r;
            rep(i,j+1,n){
                r.pb(v[i]);
            }
            sort(rall(r));
            int sum=v[j]+memo1[j][a];
            rep(i,0,r1){
                sum+=r[i];
            }
            ans=max(ans,sum);
        }
        

        // if(vec.size() == k) {
        //     int sum = v[j];
        //     int temp= accumulate(vec.begin(),vec.end(),0);
        //     sum+=temp;
        //     ans=max(ans,sum);
        // }
    }
    
    cout<<ans<<endl;
}

void solve2(){}

int32_t main(){
    auto begin = chrono::high_resolution_clock::now();
    vector<bool> s= sieve(100);
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