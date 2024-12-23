#include <bits/stdc++.h>
#include <chrono>
#include <unordered_set>
using namespace std;
#define int long long

static const auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    int t;
    cin>>t;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    while(t--){
        int n,m,r,c;
        cin>>n>>m>>r>>c;
        int ans=(n*m)-(r-1)*m-c+(m-1)*(n-r);
        cout<<ans<<endl;
    }
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}