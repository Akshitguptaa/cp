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
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        for(int i=1;i<n;i++){
            if(v[i]==1 && v[i-1]!=1){
                cout<<-1<<endl;
            }
        }
        int c=0;
        // int maxx=10000000;
        // int f;
        // while(1 && maxx--){
        //     f=1;
            // for(int i=1;i<n;i++){
                
            //     if(v[i]<v[i-1]){
            //         while(v[i]<v[i-1]){
            //         v[i]=v[i]*v[i];
            //         c++;
            //         // f=0;
            //         }
            //     }

            //     if (v[i] < v[i - 1]) {
            //         f = false;
            //         break;
            //     }
            // }
        //     if(f) break;
        // }
        // if(!f){
        //     cout<<-1<<endl;
        //     continue;
        // }

        vector<int> ops(n, 0);
 
 
	    for(int i=1;i<n;i++){ 
		    int him=v[i - 1];
		    int me=v[i];
		    int extra=0;
		    while(him!=1 && him*him <= me){
                extra--;
                him*=him;
            }
		    while(me<him){
                extra++;
                me*=me;
            }
 
		ops[i] = max(0ll, ops[i - 1] + extra);
	}
 
	    for(int i:ops){
            c+=i;
        }
        cout<<c<<endl;
    }
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}