#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

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

    vector<int> n(t);
    vector<int> k(t);

    for(int i= 0;i<t;i++){
        cin>>n[i];
    }

    for(int i=0; i<t;i++){
        cin>>k[i];
    }

    for (int i = 0;i<t;i++){
        int base=2,exp=k[i];
        int ans = 1;
        while(exp>0)
        {
            if(exp%2==1){
                ans=(1LL *ans*base) % MOD;
            }

            base=(1LL*base*base)%MOD;
            exp/=2;
        }

        cout<<ans<<endl;
    }
}