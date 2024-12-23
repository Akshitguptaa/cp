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
   
        string str1 = "PgEfTYaWGHjDAmxQqFLRpCJBownyUKZXkbvzIdshurMilNSVOtec#@_!=.+-*/";
        string str2 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        unordered_map<char,char> mp,mp2;
        for(int i=0;i<str1.size();i++){
            mp[str1[i]]=str2[i];
            mp2[str2[i]]=str1[i];
        }
        int x;
        cin>>x;
        string str,ans="";
        cin>>str;
        if(x==1){
            for(int i=0;i<str.size();i++){
                ans+=mp2[str[i]];
            }
        }
        else{
            for(int i=0;i<str.size();i++){
                ans+=mp[str[i]];
            }
        }
        cout<<ans<<endl;
}