#include <iostream>
#include <vector>
#include<algorithm>
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
        int n;
        cin >> n;
        ll sum = 0;

        if(n==1){
            cout<<-1;
            continue;
        }
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
            sum += v[i];
        }

        sort(v.begin(),v.end());

        int mid=n/2;
        int avg=sum/n;
        if(v[mid]>avg){
            cout<<-1;
            continue;
        }

        int x=1;
        while(1){
            avg+=x/n;
            if(v[mid]<avg){
                cout<<x;
                break;
            }
            x++;
        }
    }
    return 0;
}
