#include<bits/stdc++.h>
using namespace std;
bool mycmp(const pair<int,int> &a,
            const pair<int,int> &b)
{
    return (a.second <= b.first);
}

bool mycmp1(const pair<int,int> &a,
            const pair<int,int> &b)
{
    return (a.first <= b.first);
}

bool mycmp2(const pair<int,int> &a,
            const pair<int,int> &b)
{
    return (a.first <= b.second);
}
bool mycmp3(const pair<int,int> &a,
            const pair<int,int> &b)
{
    return (a.first <= b.second);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i].first;
            cin>>v[i].second;
        }
        sort(v.begin(),v.end(),mycmp3);
        sort(v.begin(),v.end(),mycmp1);
        sort(v.begin(),v.end(),mycmp);
        sort(v.begin(),v.end(),mycmp2);
        for(int i=0;i<n;i++)
        {
            cout<<v[i].first<<' '<<v[i].second<<' ';
        }
        cout<<endl;
    }
    
}