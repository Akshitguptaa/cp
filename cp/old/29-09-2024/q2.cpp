#include<iostream>
#include<cmath>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll k;
        cin >> k;
        ll l = 1,r = 2e18;

        ll ans=0;
        while (l <= r) {
            ll mid = l+(r-l)/2; 
            ll temp=sqrt(mid);
            while(temp*temp>mid) temp--;
            while((temp+1)*(temp+1)<=mid) temp++;

            ll sqr= mid-temp;
            if(sqr>=k) {
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
