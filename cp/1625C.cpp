#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#pragma GCC optimize("O3", "unroll-loops")
#define fastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout.precision(numeric_limits<double>::max_digits10);
#define ll long long
// #define int ll
#define ld long double
#define vi vector<int>
#define vvi vector<vi>
#define mii map<int,int>
#define ump unordered_map
#define pii pair<int,int>
#define vpii vector<pii>
#define rep(i,x,y) for(int i=x;i<y;i++)
#define repr(i,x,y) for(int i=x;i>=y;i--)
#define vin(v,n) rep(i,0,n)cin>>v[i] //vector input
#define vout(v,n) rep(i,0,n)cout<<v[i]<<' ' //vector output
#define pb push_back
#define all(x) x.begin(),x.end()
#define allr(x) x.begin(),x.end(),greater<int>()
#define imx INT_MAX
#define imn INT_MIN
#define ff first
#define ss second
#define WAIT cout<<"WAIT"<<endl;
#define clone(a,b,n) vi b(n);rep(i,0,n)b[i]=-v[i];
#define M 1000000007
#define endl "\n"
/*SCHRODINGER'S TEMPLATE*/
ll gcd(int a,int b)//EUCLEDIAN GCD
{
    if(b==0)return a;
    return gcd(b,a%b);
}
//vi spr;//SEIVE'S PRIME STORAGE
void seive(vector<int>&spr)//SEIVE OF ERATOSTHENES
{
    spr.resize(1e7,1);
    spr[0]=0;
    spr[1]=0;
    for(int i=2;i*i<1e7;i++)
    if(spr[i]==1)for(int j=i*i;j<1e7;j+=i)spr[j]=0;
}
//vi spf;//SPF STORAGE
ll max(int x,int y)
{
    if(x>y)return x;
    return y;
}
ll min(int x,int y)
{
    if(x>y)return y;
    return x;
}
int apna_lower_bound(vector<int>&v,int target)
{
    int lo= 0,hi=v.size()-1,ans=-1;
    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        if(v[mid]<=target)
        {
            ans=mid;
            lo=mid+1;
        }
        else hi=mid-1;
    }
    return ans;
}
void spfac(vector<int>&spf)//SMALLEST PRIME FACTOR
{
    spf.resize(1e7);
    rep(i,0,1e7)spf[i]=i;
    for(int i=2;i*i<1e7;i++)
    if(spf[i]==i)for(int j=i*i;j<1e7;j+=i)if(spf[j]==j)spf[j]=i;
}
ll biexp(int a,int b)//BINARY EXPONENTIATION USING MOD
{
    int res=1;
    while(b!=0){
    if(b%2==1)
    {
        res=((res%M)*(a%M))%M;
    }
    a=((a%M)*(a%M))%M;
    b/=2;
    }
 return res;
}
void yes(){cout<<"YES"<<endl;}
void no(){cout<<"NO"<<endl;}
int dp[505][505][505]={-1};
// void pre()
// {
//     rep(i,0,505)rep(j,0,505)rep(k,0,505)dp[i][j][k]=-1;
// }
int func(int i,int prev,int cr,int n,int k,vi&v1,vi&v2,int l)
{
    if(i>n)return 0;
    if(i==n)return (l-v1[n-1])*v2[prev];
    if(dp[i][cr][prev]!=-1)return dp[i][cr][prev];
    int x=imx;
    if(cr<k)x=min(x,(v1[i]-v1[i-1])*v2[prev]+func(i+1,prev,cr+1,n,k,v1,v2,l));
    x=min(x,(v1[i]-v1[i-1])*v2[prev]+func(i+1,i,cr,n,k,v1,v2,l));
    return dp[i][cr][prev]=x;
}
void Schrodinger()//SOLVING FUNCTION
{
    memset(dp, -1, sizeof(dp));
    int n,l,k;
    cin>>n>>l>>k;
    vi v1(n),v2(n);
    vin(v1,n);
    vin(v2,n);
    // vector<vvi>dp(n+1,vvi(n+1,vi(n+1,-1)));
    cout<<func(1,0,0,n,k,v1,v2,l)<<endl;
}
int32_t main()
{
    fastIO
    int t=1;
    // cin>>t;
    // pre();
    while(t--)
    {
        Schrodinger();
    }
}
