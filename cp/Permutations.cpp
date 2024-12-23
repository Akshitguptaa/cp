#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n==3 || n==2){
        cout<<"NO SOLUTION";
        return 0;
    }
    vector<int> v;
    for(int i=2;i<=n;i+=2){
        v.push_back(i);
    }
    for(int i=1;i<=n;i+=2){
        v.push_back(i);
    }
    for(int i:v){
        cout<<i<<" ";
    }
}