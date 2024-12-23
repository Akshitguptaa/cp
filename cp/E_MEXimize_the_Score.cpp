#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define int long long
const int MOD = 998244353;

static const auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int mexx(const vector<int>& v) {
    unordered_set<int> s(v.begin(),v.end());
    
    int mex=0;
    while(s.count(mex)) {
        mex++;
    }
    return mex;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        vector<int> m;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(v[i]==0) m[i]=1;
            else m[i]=1;
        }

        
    }
}