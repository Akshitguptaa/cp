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
        int n;
        cin>>n;
        vector<int> v(n);
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(i<n-2){
                sum+=v[i];
            }
        }
        cout<<(v[n-1]-v[n-2]+sum)<<endl;
    }
}