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
        int a,b;
        cin>>a>>b;
        if(b%2!=0 && a>=2){
            a-=2;
            b--;
        }
        if(a%2==0 && b%2==0){
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}