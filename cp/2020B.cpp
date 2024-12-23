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
    int k;
    cin>>k;

    int m=(sqrt(1+4*k)-1)/2;
    int l=m*m;
    int r=1+2*k;
    int ans=0;
 
    while(l<=r){
        int mid = l+(r-l)/2; 
        int temp=sqrt(mid);
        while(temp*temp>mid) temp--;
        while((temp+1)*(temp+1)<=mid) temp++;
        int sqr= mid-temp;

        if(sqr>=k) {
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
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