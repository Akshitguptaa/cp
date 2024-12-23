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
        int x,y,k;
        cin>>x;
        cin>>y;
        cin>>k;
        int ax,ay,bx,by,cx,cy,dx,dy;
        ax = 0,ay = 0;
        bx = min(x,y);
        by = min(x,y);
        cx = 0;
        cy = min(x, y);
        dy = 0;
        dx = min(x, y);
        cout<<ax <<" "<<ay<<" "<<bx<<" "<<by<<endl;
        cout<<cx <<" "<<cy<<" "<<dx<<" "<<dy<<endl;
    }
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}