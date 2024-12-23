#include<bits/stdc++.h>
using namespace std;

static const auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int main() {
    int tt; 
    cin>>tt;
    while (tt--){
        string s,t;
        cin>>s>>t;
        int n1=s.size();
        int n2=t.size();

        if(s[0]!=t[0]){
            cout<<n1+n2<<endl;
            continue;
        }
        int c=0;

        for(int i =0;i<min(n1,n2);i++){
            if(s[i]==t[i]){
                c++;
            }else{
                break;
            }
        }
        cout<<min(n1+n2-c+1,n1+n2)<<endl;
    }
}