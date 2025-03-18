#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3", "unroll-loops")
#define fastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout.precision(numeric_limits<double>::max_digits10);
#define ll long long
#define int ll
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
#define clone(a,b,n) vi b(n);rep(i,0,n)b[i]=-v[i];
#define M 1000000007
#define nl "\n"
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
/*---------------------------------------------------------------------------------------------------------------------------------*/
void Schrodinger()//SOLVING FUNCTION
{
    /*--------------------CODE GOES HERE--------------------*/
    int n,m;
    cin>>n>>m;
    vi v(m);
    vin(v,m);
    sort(all(v));
    vi ps(m);
    rep(i,0,m)if(v[i]==n)v[i]--;
    ps[0]=v[0];
    // cout<<ps[0]<<" ";
    rep(i,1,m){
        ps[i]=ps[i-1]+v[i];
        // cout<<ps[i]<<" ";
    }
    // rep(i,0,m)ps[i]=rs-ps[i]+1;
    int ans=0;
    rep(i,0,m)
    {
        int rs=n-v[i];
        int x=lower_bound(v.begin()+i+1,v.end(),rs)-v.begin();
        if(x==m)continue;
        // if(x==i)x++;
        ans+=(rs*(m-x)-(ps[m-1]-ps[x]+v[x]+(m-x)))*2;
        // rep(j,x,m)
        // {
        //     ans+=v[j]
        // }
    }
    cout<<-1*ans<<endl;
}
int32_t main()
{
    fastIO
    int t;
    cin>>t;
    while(t--)
    {
        Schrodinger();
    }
}
