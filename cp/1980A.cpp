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

// utitily
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

void solve(){
    int n,m;
    cin>>n>>m;
    string st;
    cin>>st;
    unordered_map<char,int> mp;
    for(int i=0;i<n;i++){
        mp[st[i]]++;
    }
    int c=0;
    for(char ch='A';ch<='G';ch++){
        if(mp[ch]<m){
            c+=m-mp[ch];
        }
    }
    cout<<c<<endl;
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