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
    double r;
    cin>>r;
    double pi= 3.141592653;
    cout<<fixed<<setprecision(9)<<pi*r*r;
}