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
        int n;
        cin>>n;
 
        string r1;
        string r2;
        cin>> r1;
        cin>> r2;
 
        int ans = 0;
        int c;
        for(int i=0; i<n; i+=3){
            c=0;
            for(int j=0;j<3;j++){
                if(i+j < n){
                    if (r1[i + j] == 'A') c++;
                    if (r2[i + j] == 'A') c++;
                }
            }
            if(c>=4){ 
                ans+=2;
            }else if(c>=2){
                ans++;
            }
        }
 
        cout<<ans<<endl;
    }
}