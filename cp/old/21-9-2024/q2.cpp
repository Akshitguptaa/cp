#include <iostream>
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
        ll n, k;
        cin >> n;
        cin >> k;

        ll ans=0;
        if(n<=k){
            ans=n*(n+1)/2;
        }
        else{
            ans=(k*(k+1))/2+(n-k)*k;
        }

        if (ans % 2 == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
