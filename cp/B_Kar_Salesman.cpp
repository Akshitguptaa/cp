#include<bits/stdc++.h>
using namespace std;
#define int long long

static const auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int32_t main() {
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x; 
        vector<int> a(n);
        int sum=0;
        int maxx=INT_MIN;
        for(int i=0;i<n;i++){
            cin>>a[i]; 
            maxx=max(a[i],maxx);
            sum+=a[i];
        }
        if(n==1){
            cout<<a[0]<<endl;
            continue;
        }
        sort(a.rbegin(),a.rend());

        // int ans = 0;
        
        // while(1){
        //     int s = 0;
        //     for(int i=0;i<n;i++){
        //         if(s>=x) break;
        //         if(a[i]>0){ 
        //             s++;
        //             a[i]--;
        //         }
        //     }
        //     if(s==0) break;

        //     ans++;
        // }

        int ans = max((sum +x-1)/x,maxx);

        cout<<ans<<endl; 
    }
    return 0;
}
