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
    int n,m;
    cin>>n>>m;
    vector<vector<char>> v(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    int x,y;
    cin>>x>>y;
    if(v[x+1][y]=='.'|| v[x][y+1]=='.' || v[x-1][y]=='.' || v[x][y-1]=='.' || v[x-1][y-1]=='.' || v[x+1][y+1]=='.' || v[x-1][y+1]=='.' || v[x+1][y-1]=='.'){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
}