#include<bits/stdc++.h>
#include<unordered_set>
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
        int a,b;
        cin>>a>>b;
        if(a>=b) {cout<<a<<endl; continue;}
        if(b>=2*a) {cout<<0<<endl; continue;}

        cout<<(2*a)-b<<endl;        
    }
}