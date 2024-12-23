#include<bits/stdc++.h>

using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        long long n, k;
        cin>>n>>k;

        if (k == 1) {
            cout << n << endl;
        } else {
            int ans = 0;
            while(n){
                ans += n % k;
                n /= k;
            }
            cout << ans << endl;
        }
    }
    return 0;
}