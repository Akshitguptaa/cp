#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{

    int t = 1;
    cin >> t;
    vector<int> ans;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        ans.push_back(v[n / 2 ]);
        v.clear();
    }
    for (int result : ans)
    {
        cout << result << endl;
    }
}