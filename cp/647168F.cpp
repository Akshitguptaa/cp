#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M1=1000000007, M2=1000000009, P1=91138233, P2=89164201;

int n, q;
vector<int> a;
vector<int> segSum, segH1, segHInv1, segH2, segHInv2, lazyAdd;
int P1inv, P2inv;

int modpow(int base, int exp, int mod){
    int res = 1;
    base %= mod;
    while(exp > 0){
        if(exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

void apply_effects(int idx, int l, int r, int val, int mul1, int mulInv1, int mul2, int mulInv2){
    segSum[idx] += (r - l + 1) * val;
    segH1[idx] = (segH1[idx] * mul1) % M1;
    segHInv1[idx] = (segHInv1[idx] * mulInv1) % M1;
    segH2[idx] = (segH2[idx] * mul2) % M2;
    segHInv2[idx] = (segHInv2[idx] * mulInv2) % M2;
    lazyAdd[idx] += val;
}

void apply(int idx, int l, int r, int val){
    int exp1 = (val % (M1-1) + (M1-1)) % (M1-1);
    int exp2 = (val % (M2-1) + (M2-1)) % (M2-1);
    int mul1 = modpow(P1, exp1, M1), mul2 = modpow(P2, exp2, M2);
    int mulInv1 = modpow(P1inv, exp1, M1), mulInv2 = modpow(P2inv, exp2, M2);
    apply_effects(idx, l, r, val, mul1, mulInv1, mul2, mulInv2);
}

void pushDown(int idx, int l, int r){
    if(lazyAdd[idx] == 0) return;
    int val = lazyAdd[idx], mid = (l + r) / 2;
    int exp1 = (val % (M1-1) + (M1-1)) % (M1-1);
    int exp2 = (val % (M2-1) + (M2-1)) % (M2-1);
    int mul1 = modpow(P1, exp1, M1), mul2 = modpow(P2, exp2, M2);
    int mulInv1 = modpow(P1inv, exp1, M1), mulInv2 = modpow(P2inv, exp2, M2);
    apply_effects(2*idx, l, mid, val, mul1, mulInv1, mul2, mulInv2);
    apply_effects(2*idx+1, mid+1, r, val, mul1, mulInv1, mul2, mulInv2);
    lazyAdd[idx] = 0;
}

void pullUp(int idx) {
    segSum[idx] = segSum[2*idx] + segSum[2*idx+1];
    segH1[idx] = (segH1[2*idx] + segH1[2*idx+1]) % M1;
    segHInv1[idx] = (segHInv1[2*idx] + segHInv1[2*idx+1]) % M1;
    segH2[idx] = (segH2[2*idx] + segH2[2*idx+1]) % M2;
    segHInv2[idx] = (segHInv2[2*idx] + segHInv2[2*idx+1]) % M2;
}

void build(int idx, int l, int r){
    lazyAdd[idx] = 0;
    if(l == r){
        segSum[idx] = a[l];
        int exp1 = (a[l] % (M1-1) + (M1-1)) % (M1-1);
        int exp2 = (a[l] % (M2-1) + (M2-1)) % (M2-1);
        segH1[idx] = modpow(P1, exp1, M1);
        segHInv1[idx] = modpow(P1inv, exp1, M1);
        segH2[idx] = modpow(P2, exp2, M2);
        segHInv2[idx] = modpow(P2inv, exp2, M2);
        return;
    }
    int mid = (l + r) / 2;
    build(2*idx, l, mid);
    build(2*idx+1, mid+1, r);
    pullUp(idx);
}

void update(int idx, int l, int r, int ql, int qr, int val){
    if(qr<l || ql>r) return;
    if(ql<=l && r<=qr){ apply(idx,l,r,val); return; }
    pushDown(idx,l,r);
    int mid = (l+r)/2;
    update(2*idx,l,mid,ql,qr,val);
    update(2*idx+1,mid+1,r,ql,qr,val);
    pullUp(idx);
}

void query(int idx, int l, int r, int ql, int qr, int &outSum,int &outH1,int &outHInv1,int &outH2,int &outHInv2){
    if(qr<l || ql>r) return;
    if(ql<=l && r<=qr){
        outSum += segSum[idx];
        outH1 = (outH1 + segH1[idx]) % M1;
        outHInv1 = (outHInv1 + segHInv1[idx]) % M1;
        outH2 = (outH2 + segH2[idx]) % M2;
        outHInv2 = (outHInv2 + segHInv2[idx]) % M2;
        return;
    }
    pushDown(idx,l,r);
    int mid = (l+r)/2;
    query(2*idx,l,mid,ql,qr,outSum,outH1,outHInv1,outH2,outHInv2);
    query(2*idx+1,mid+1,r,ql,qr,outSum,outH1,outHInv1,outH2,outHInv2);
}

void solve(){
    cin >> n >> q;
    a.resize(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];

    segSum.assign(4*n+4,0);
    segH1.assign(4*n+4,0);
    segHInv1.assign(4*n+4,0);
    segH2.assign(4*n+4,0);
    segHInv2.assign(4*n+4,0);
    lazyAdd.assign(4*n+4,0);

    P1inv = modpow(P1, M1-2, M1);
    P2inv = modpow(P2, M2-2, M2);
    build(1,1,n);

    while(q--){
        int x,l,r; cin >> x >> l >> r;
        if(x==1){ int val; cin >> val; update(1,1,n,l,r,val); }
        else{
            int totalSum=0,H1=0,HInv1=0,H2=0,HInv2=0;
            query(1,1,n,l,r,totalSum,H1,HInv1,H2,HInv2);
            int N=r-l+1;
            if((2*totalSum)%N!=0){ cout<<"NO\n"; continue; }
            int S=(2*totalSum)/N;
            int expS1 = (S%(M1-1)+(M1-1))%(M1-1);
            int expS2 = (S%(M2-1)+(M2-1))%(M2-1);
            int P1S = modpow(P1,expS1,M1), P2S = modpow(P2,expS2,M2);
            int Htrans1 = (P1S*HInv1)%M1, Htrans2 = (P2S*HInv2)%M2;
            if(H1==Htrans1 && H2==Htrans2) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output2.txt", "w", stdout);
   #endif
    solve();
    return 0;
}