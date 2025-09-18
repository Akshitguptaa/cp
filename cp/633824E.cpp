#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {

vector<long double>v(4,0);
for(int i=0;i<4;i++)cin>>v[i];

long double x;
cin>>x;
x*=(3.0);
sort(v.begin(),v.end());

long double temp=x-(v[1]+v[2]);
if(x<v[0]+v[1]+v[2]){
    cout<<"impossible"<<endl;
}
else if(x>=v[2]+v[1]+v[3]){
    cout<<"infinite"<<endl;
}
else cout<<fixed<<setprecision(2)<<temp<<endl;

}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    // cin >> t;
    // while (t--) 
    solve();
    return 0;
}