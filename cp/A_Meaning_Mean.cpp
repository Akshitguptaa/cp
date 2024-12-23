#include<bits/stdc++.h>
using namespace std;

#define int long long

static const auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int avg=(v[0]+v[1])/2;
        for(int i=2;i<n;i++){
            avg=(v[i]+avg)/2;
        }
        cout<<avg<<endl;
    }
}