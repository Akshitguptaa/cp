//// AKSHIT - template ////

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
#define PI 3.1415926535897932384626433832795

// i/o
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

// vector operationss
using vi = vector<int>;
using vb = vector<bool>;
using v32 = vector<int32_t>;
template <class T>
void debug(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }
template <class T>
void in(vector<T> &v) { for(int i=0;i<v.size();i++) cin>>v[i];}
template <class T>
void dis(vector<T> &v) {  for (auto x : v) cout << x << " "; cout << endl; }
template <class T>
void sortv(vector<T> &v) { sort(v.begin(),v.end()); }


void solve(){
    int n,k;
    cin>>n>>k;
    vi v(k);
    int c=0;
    for(int i=0;i<k;i++){
        cin>>v[i];
        if(v[i]==1){
            c++;
        }
    }
    sortv(v);
    int c1=0;
    for(int i=0;i<k;i++){
        if(v[i]>1 && i!=k-1){
            c1+=v[i]-1;
            c+=v[i];
        }    
    }
    cout<<c+c1<<endl;
}

void solve2(){
    int n,k;
    cin>>n>>k;
    vi v(k);
    in(v);
    int p=0;
    int maxx=0;
    for(int i=0;i<k;i++){
        if(v[i]>maxx){
            maxx=v[i];
            p=i;
        }
    }
    int c=0,c1=0;
    for(int i=0;i<k;i++){
        if(i!=p){
            c+=(v[i]-1);
            c1+=v[i];
        }
    }
    cout<<c+c1<<endl;
}

int32_t main(){
    faster;
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