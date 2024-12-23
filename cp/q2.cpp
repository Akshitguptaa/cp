#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    vector<int> v;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> v1(n);
        for(int i =0;i<n;i++){
            cin>>v1[i];
        }

        
    }
    for (int i : v)
    {
        cout << i << endl;
    }
}
