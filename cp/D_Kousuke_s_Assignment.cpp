#include <bits/stdc++.h>
#include <unordered_set>
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
        int n;
        cin >> n;
        vector<int> v(n);
        vector<int> v1(n+1,0);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            v1[i+1]=v[i]+v1[i];
        }
        // unordered_map<int, int> mp;
        int sum = 0,c=0;
        // int r = -1; 
        // mp[0] = -1;
        set<int> s;
        for(int i=0;i<=n;i++){
            if(!s.insert(v1[i]).second){
                c++;
                s={v1[i]};
            }
        }
        cout<<c<<endl;
        // for (int i=0;i<n;i++)
        //     {
        //         sum+=v[i];

        //         if(mp.find(sum)!=mp.end())
        //         {
        //         if(mp[sum]>=r){
        //             c++;
        //             r = i; 
        //             }
        //         }
        //         mp[sum] = i;
        //     }

            // cout<<c<<endl;
    }
}