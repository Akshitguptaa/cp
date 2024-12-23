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
        vector<int> w(n);
        vector<int> h(n);
        int maxx=INT_MIN;
        int maxi=INT_MIN;
        for(int i =0;i<n;i++){
            cin>>w[i];
            cin>>h[i];
            maxx=max(maxx,w[i]);
            maxi=max(maxi,h[i]);
        }
        cout<<2*(maxx+maxi)<<endl;
    }
}