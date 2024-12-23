#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n;
    cin>>n;
    int s=n*(n+1)/2;
    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;
        s-=x;
    }
    cout<<s;
    return 0;
}