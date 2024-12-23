#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int size = str.size();
    if (size == 1)
    {
        cout << 1;
        return 0;
    }
    int l = 0, maxx = INT_MIN;
    char ch = str[0];
    int freq = 1;
    for (int r = 1; r < size; r++)
    {
        if (str[r] == ch)
        {
            freq++;
        }
        else
        {
            ch = str[r];
            freq = 1;
        }
        maxx = max(freq, maxx);
    }
    cout << maxx;
}