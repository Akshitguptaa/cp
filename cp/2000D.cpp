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
    int n;
    cin>>n;
    vi v(n);
    inp(v);
    string s;
    cin>>s;
    int l=0,r=s.length()-1;
    vi pre(n+1,0);
    // pre[0]=v[0];
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+v[i-1];
    }
    int sum=0;
    while(l<r){
        while(s[l]!='L' && l<r){
            l++;
        }
        while(s[r]!='R' && r>l){
            r--;
        }
        if(l>=r){
            break;
        }
        sum+=pre[r+1]-pre[l];
        s[l]=s[r]='.'; 
        l++;
        r--;
    }
    cout<<sum<<endl;
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