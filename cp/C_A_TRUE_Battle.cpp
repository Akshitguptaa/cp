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
    while (t--){
        int n;
        cin>>n;
        string s;
    cin>>s;
    
        int flag=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='1' && s[i+1]=='1'){
                flag=1;    break;
            }
        }
        if(s[0]=='1') flag=1;
        if(s[n-1]=='1') flag=1;
    
        if(flag) cout<<"YES"<<endl;
        else{
        cout<<"NO"<<endl;
        }
    }
}