#include <bits/stdc++.h>
#include <chrono>
#include <unordered_set>
using namespace std;
#define int long long

static const auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    int t;
    cin>>t;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        unordered_map<int,int> mp;
        for(int i =0;i<k;i++){
            int b,c;
            cin>>b>>c;
            mp[b]+=c;
        }
        
        priority_queue<int> pq;

        for(auto p:mp){
            pq.push(p.second);
        }

        int ans=0;
        int s=pq.size();
        for(int i =0;i<min(n,s);i++){
            // if(pq.empty()) break;
            ans+=pq.top();
            pq.pop();
        }
        cout<<ans<<endl;
    }
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}