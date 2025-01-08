#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define pb push_back

static const auto init = []() { 
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0); 
    return 0;
}();

// Segment tree for both min and max
struct SegTree {
    vector<pair<int,int>> tree;  // {min, max}
    int n;
    
    SegTree(int size) : n(size) {
        tree.resize(4 * n, {LLONG_MAX, LLONG_MIN});
    }
    
    void build(vector<int>& a, int node, int start, int end) {
        if(start == end) {
            tree[node] = {a[start], a[start]};
            return;
        }
        int mid = (start + end) >> 1;
        build(a, 2*node+1, start, mid);
        build(a, 2*node+2, mid+1, end);
        tree[node].first = min(tree[2*node+1].first, tree[2*node+2].first);
        tree[node].second = max(tree[2*node+1].second, tree[2*node+2].second);
    }
    
    void update(int node, int start, int end, int idx, int val) {
        if(start == end) {
            tree[node] = {val, val};
            return;
        }
        int mid = (start + end) >> 1;
        if(idx <= mid) update(2*node+1, start, mid, idx, val);
        else update(2*node+2, mid+1, end, idx, val);
        tree[node].first = min(tree[2*node+1].first, tree[2*node+2].first);
        tree[node].second = max(tree[2*node+1].second, tree[2*node+2].second);
    }
    
    pair<int,int> query(int node, int start, int end, int l, int r) {
        if(r < start || end < l) return {LLONG_MAX, LLONG_MIN};
        if(l <= start && end <= r) return tree[node];
        int mid = (start + end) >> 1;
        auto left = query(2*node+1, start, mid, l, r);
        auto right = query(2*node+2, mid+1, end, l, r);
        return {min(left.first, right.first), max(left.second, right.second)};
    }
};

int findMaxValue(int n, vector<int>& a) {
    SegTree st(n);
    st.build(a, 0, 0, n-1);
    
    int result = 0;
    // For each possible length
    for(int len = 0; len <= n-1; len++) {
        // Check each window of current length
        for(int i = 0; i + len < n; i++) {
            auto [minVal, maxVal] = st.query(0, 0, n-1, i, i+len);
            result = max(result, maxVal - minVal - len);
        }
    }
    return result;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    // Print initial answer
    cout << findMaxValue(n, a) << endl;
    
    // Process queries
    while(q--) {
        int idx, val;
        cin >> idx >> val;
        idx--;
        a[idx] = val;
        cout << findMaxValue(n, a) << endl;
    }
}

int32_t main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}