#include <bits/stdc++.h>
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
    int t;
    cin>>t;

    while(t--){
        int n ;
        cin>>n;
        int maxx=0;
        int minn=INT_MAX;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            minn=min(x,minn);
            maxx=max(x,maxx);
        }
        cout<<(maxx-minn)*(n-1)<<endl;
    }
}