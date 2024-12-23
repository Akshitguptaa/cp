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
#define all(x) begin(x), end(x)

// i/o
static const auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();

// utitily
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

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

void solve(){
    int n;
    cin>>n;
    vi v(n);
    inp(v);
    int m;
    cin>>m;
    while(m--){
        string str;
        cin>>str;
        int s=str.length();
        if(s!=n){
            no();continue;
        }
        unordered_map<char, int> mp;
        unordered_map<int, char> mp1;
        int f = 1;

        for(int i=0;i<s;i++){
            char c=str[i];
            int val=v[i];

            if(mp.count(c)>0){
                if(mp[c]!=val){
                    no();
                    f=0;
                    break;
                }
            }else{
                mp[c]= val;
            }

            if(mp1.count(val)>0){
                if(mp1[val]!=c){
                    no();
                    f=0;
                    break;
                }
            }else{
                mp1[val]=c;
            }
        }

        if(f){
            yes();
        }
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