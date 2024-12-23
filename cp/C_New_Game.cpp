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
        int n,k;
        cin >>n>>k;
        vector<int> v(n);
        unordered_map<int, int> mp;
 
        for (int i=0; i<n; i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int maxx=0;
        int diff=0,left=0;
        for (int i=0;i<n;i++){
            if(mp[v[i]]==0){
                diff++;
            }
            mp[v[i]]++;
            while(diff>k){
                mp[v[left]]--;
                if(mp[v[left]]==0){
                    diff--;
                }
                left++;
            }
            if (i>0 &&(v[i]== v[i-1] || v[i]==v[i-1]+1)){
                maxx = max(maxx, i-left+1);
            }

        }
        cout<<maxx<<endl;
    }
}