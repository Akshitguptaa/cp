#include <bits/stdc++.h>
using namespace std;

#define MAX (1 << 17) 

bool present[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        present[x] = true;
    }

    int q; cin >> q;
    while(q--) {
        int x; cin >> x;
        int mask = ((1 << 17) - 1) ^ x;
        bool found = false;

        for (int sub = mask; ; sub = (sub - 1) & mask) {
            if (present[sub]) {
                found = true;
                break;
            }
            if (sub == 0) break;
        }

        cout << (found ? "YES" : "NO") << "\n";
    }

    return 0;
}

// segment tree
vector<int> t;
#define INF ((1LL << 32) - 1)
 
int combine(int a, int b) {
    return a + b;
}
 
void build(vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}
 
int func(int v,int tl,int tr,int l,int r){
    if(l > r){
        return INF;
    }
    if(l==tl && r==tr){
        return t[v];
    }
    int tm= (tl+tr)/2;
 
    return combine(func(v*2, tl, tm, l, min(r,tm)), func(v*2+1, tm+1, tr, max(l,tm+1),r));
}