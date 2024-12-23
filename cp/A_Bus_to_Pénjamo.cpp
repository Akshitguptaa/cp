#include<bits/stdc++.h>
using namespace std;

static const auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int main() {
    int t; 
    cin>>t;
    while (t--){
        int n,r; 
        cin >>n>>r;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }

        int odd = 0;
        int total = 0;

        for (int i : v) {
            if (i % 2) odd++;
            total+=i;
        }
        int ans = total, left = r * 2;

        if(total <= left){
            int temp = max(0, odd-(left -total));
            ans -= temp;
        }
        cout<<ans<<endl;
    }
    return 0;
}
