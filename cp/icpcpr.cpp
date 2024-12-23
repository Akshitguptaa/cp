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


void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    vector<int> dp(n + 1, 0);
    
    dp[0] = 0;
    vector<int> pr(n + 1, 0);
    for (int i=0;i<n;i++) {
        pr[i+1]=pr[i]+v[i];
    }

    for (int m=1;m<=n;m++) {
        dp[m]=dp[m-1] + v[m-1];
        
        if(m>=k+1){
            int grp = pr[m]-pr[m-(k+1)];
            dp[m] = min(dp[m],dp[m-(k+1)]+grp-v[m-(k+1)]);
        }
    }

    for (int m = 1; m <= n; ++m) {
        cout <<dp[m]<< " ";
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