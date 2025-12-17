#include "bits/stdc++.h"
#include <mutex>
#include <future>
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef DEBUG
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
struct testcase {
    int n,id;
    bool res=0;
    string s;
    void read(int ID) { // read in test data
        id=ID;
        cerr << "read: " << id << endl;
        cin >> n >> s;

    }
    void solve() {
        cerr << "solve: " << id << endl;
        int pref=0;
        for(int i=n-1;i>=0;--i) {
            pref+=s[i]=='B'?1:-1;
            if(pref<0) {
                res=1;
            }
        }

    }
    void write(ofstream& cout) {
        if(id) cout << '\n';
        cout << "Case #" << id+1 << ": " << (res?"Alice":"Bob");
    }
};
vector<testcase> tests;
const int PARALLEL=8;
void paralleltests(int l=0, int r=PARALLEL-1) {
    if (l==r) {
        for(int i=l;i<(int)tests.size();i+=PARALLEL) {
            tests[i].solve();
        }
        return;
    }
    ll mid = (l+r)/2;
    auto handle = std::async(launch::async,paralleltests, l,mid);
    paralleltests(mid+1,r);
    handle.wait();
}
struct timetracker {
	chrono::microseconds timetaken;
	std::chrono::steady_clock::time_point begin;
	void begintimer() {
		begin = chrono::steady_clock::now();
	}
	chrono::microseconds thismovedur() { return chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - begin); }
	void endtimer() {
		timetaken += thismovedur();
	}
} TMT;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    TMT.begintimer();
    freopen("real.txt","r",stdin);
    int T=8; 
    cin >> T;
    tests.resize(T);
    {
    int id=0;
    for(auto& t : tests) t.read(id++);
    }
    #ifdef DEBUG
    for(auto& t : tests) t.solve();
    #else
    paralleltests();
    #endif
    ofstream fout("D.out");
    for(auto& t : tests) {
        t.write(fout);
    }
    TMT.endtimer();
    cout << TMT.timetaken.count()*1e-6 << " seconds\n";
}

// ulimit -s 1000000 
// (in kB)