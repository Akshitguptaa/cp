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
        cin >> n;
        string str="";
        for(int i=0;i<n-1;i++){
            str+="0";
        }
        str+="1";
        cout<<str << endl;  
    }
}