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
    
    
}

void solve2(){}

int32_t main(){
    faster;
    auto begin = chrono::high_resolution_clock::now();
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    string s;
    cin>>s;
    vi v(3,0);
    v[0]=1;
    for(int i=0;i<s.length();i++){
        if(s[i]=='A'){
            swap(v[0],v[1]);
        }
        if(s[i]=='B'){
            swap(v[1],v[2]);
        }
        if(s[i]=='C'){
            swap(v[0],v[2]);
        }
    }
    for(int i =0;i<3;i++){
        if(v[i]==1){
            cout<<i+1<<endl;
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}