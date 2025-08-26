int gcd(int a,int b) { if (b==0) return a; return gcd(b, a%b); }
int lcm(int a,int b) { return a/gcd(a,b)*b; }
ll getMinUpgradationTime(int req1, int t1, int req2, int t2) {
    ll lcm = lcm(req1, req2);
    ll lo=0, hi = 1e18, ans=-1;
    while(lo<=hi) {
        ll mid = lo+(hi-lo)/2;
        ll tt1 = mid - mid/req1;
        ll tt2 = mid - mid/req2;
        ll t = mid - mid/lcm;
        
        if(t >= t1+t2 && tt1 >= t1 && tt2 >= t2) {
            ans = mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    return ans;
}