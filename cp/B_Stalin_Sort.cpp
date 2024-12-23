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
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int x=v[0];
        int c=0;
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        // for(int i=0;i<n;i++){
        //     if(v[i]>x){
        //         c++;
        //         // continue;
        //     }
        //     x=v[i];
        // }
        int ans = n;
        for(int i=0;i<n;i++) {
            int c=0;
            for(int j=0;j<n;j++) {
                if(j<i||v[j]>v[i]) {
                    c++;
                }
        }
            ans = min(ans, c);
        }
    cout << ans << "\n";
    }
}