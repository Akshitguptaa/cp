#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    vector<int> v;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        int t = (n + min(x, y) - 1) / min(x, y);
        v.push_back(t);
    }
    for (int i : v)
    {
        cout << i << endl;
    }
}
