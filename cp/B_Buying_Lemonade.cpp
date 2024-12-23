#include <bits/stdc++.h>
using namespace std;
#define int long long

static const auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n>>k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }


        sort(v.begin(),v.end());

        vector<int> vp(n);
        vp[0]=v[0];
        int ans=0;
        int i=0;
        for(i=0;i<n;i++){
            ans+=(v[i]*(n-i+1));
            if(ans==k){
                break;
            }
        }
        cout<<ans+i<<endl;


        // int ans=0;
        // int flag=0;
        // int c=0;
        // while(1){
        //     int f1=1;
        //     for(int i =c;i<n;i++){
        //         if(v[i]==0){
        //             c++;
        //             if(c==n){
        //                 if(ans<k){
        //                     cout<<0<<endl;
        //                     // fla
        //                     break;
        //                 }
        //             }
        //             continue;
        //         }
        //         if(v[i]>0){
        //             v[i]--;
        //             ans++;
        //             f1=0;
        //         }
        //         if(ans>=k){
        //             flag=1;
        //             break;
        //         }
        //     }
        //     if(flag==1 || f1==1 ) break;
        // }
        // int c = count(v.begin(), v.end(), 0);
        // cout << ans + c << endl;
    }
}