#include <bits/stdc++.h>
using namespace std;
#define int long long

static const auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

bool sorted(vector<int> v){
    for(int i=0;i<v.size()-1;i++){
        if(v[i]>v[i+1]) return 0;
    }
    return 1;
}

void func(vector<int> v,int q,string str,int x){
    if(sorted(v)){
    int r=0,l=0;
    for(char ch :str){
        if(ch=='R') r++;
        else l++;
    }
    if(x%2==0) cout<<"YES";return;
    }
    
}

int32_t main()
{
    int t;
    cin>>t;    
    while (t--){
        int n,q;
        cin>>n>>q;
        vector<int>v(n);
        for(int i =0;i<n;i++){
            cin>>v[i];
        }
        string str;
        cin>>str;

        vector<int> v1(q);
        for(int i =0;i<q;i++){
            int x;
            cin>>x;
            func(v,q,str,x);
            cout<<endl;
        }

    }
}