#include <bits/stdc++.h>
#include<chrono>
#include<unordered_set>
using namespace std;
typedef long long int int64;
typedef unsigned long long int uint64;

#define int long long
#define endl "\n"
#define INF LLONG_MAX
#define MOD 1000000007

using vi = vector<int>;
using vb = vector<bool>;
using v32 = vector<int32_t>;

// i/o
static const auto init = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();


void solve(){
    int n=3;
    vi v1(n);   
    vi v2(n);   
    vi v3(n);   
    for(int i=0;i<n;i++){
        cin>>v1[i];
        cin>>v2[i];
        cin>>v3[i];
    }
}
bool check(vi x,vi y) {
    bool f = 0;
    for(int i=0;i<3;i++){
        if(x[i]<y[i]) return 0;  
    }
    for(int i=0;i<3;i++){
        if(x[i]>y[i])f=1;
    }
    return f;
}

void solve2(){
    int n =3;
    vector<vi> v(n,vi(3));
    for(int i =0;i<n;i++){
        cin>>v[i][0]>>v[i][1]>>v[i][2];
    }
    int f=0;
    while(next_permutation(v.begin(),v.end())){
        if(check(v[0],v[1])&& check(v[1],v[2])){
            f=1;
            break;
        }
    }
    if(f){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

int32_t main(){
    auto begin = chrono::high_resolution_clock::now();
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        // solve();
        solve2();
    }

    auto end = chrono::high_resolution_clock::now();
    
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}