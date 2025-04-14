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
    int n,q;
    cin>>n>>q;
    //  vi v(n);
    //  inp(v);

    int sum= 0;

    map<int,int> mp;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;

        mp[i+1]= x;
        sum+=x;
    }

    int f=0;
    int val= -1;
     while(q--){
        int t;
        cin>>t;
        
        if(t==1){
            int i,x;
            cin>>i>>x;
            if(mp[i]){
                sum+=x-mp[i];
            }else{
                sum+=x-val;
            }
            mp[i]= x;
            // cout<<sum<<endl;
        }else{
            int x;
            cin>>x;

            sum= n*x;
            val= x;
            mp.clear();
        }
            cout<<sum<<endl;
     }
}

void solve2(){}

int32_t main(){
        solve();
}