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

int mex(vector<int> v){
    unordered_set<int> s(v.begin(),v.end());
    int mexx=0;
    while(s.count(mexx)){
        mexx++;
    }
    return mexx;
}

int func(int x,vector<int> v){
    unordered_set<int> s(v.begin(),v.end());
    unordered_set<int> s2;
    
    int mexx=mex(v);
    for (int i : s) {
        for (int k = 0; k <= (mexx - i) / x; k++) {
            s2.insert(i + k * x);
        }
    }
    
    while (s2.count(mexx)) {
        mexx++;
    }
    
    return mexx;
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int> v(n);
        for(int i =0;i<n;i++){
            cin>>v[i];
        }
        cout<<func(x,v)<<endl;
    }
}