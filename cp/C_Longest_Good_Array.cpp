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
    // int t;
    // cin>>t;
    // // freopen("in",  "r", stdin);
    // // freopen("out", "w", stdout);

    // while(t--){
    //     int l,r;
    //     cin>>l>>r;
    //     int i;
    //     for(i=1;i<=r && l<=r;i++){
    //         l+=i;
    //     }
    //     cout<<i-1<<endl;
    // }
    cout<<(2/3)%((int)1e9+7);
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}