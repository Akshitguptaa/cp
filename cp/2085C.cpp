#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int L = 62;
const ll LIMIT = 1000000000000000000LL;
const ll INF = LIMIT + 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        ll X, Y;
        cin >> X >> Y;
        
        if(X == Y) {
            cout << -1 << "\n";
            continue;
        }
        if((X & Y) == 0) {
            cout << 0 << "\n";
            continue;
        }

        // dp[pos][carryX][carryY] represents minimum value for positions pos to L-1
        ll dp[70][2][2];
        // Initialize all states as INF
        for(int i = 0; i <= L; i++)
            for(int cx = 0; cx < 2; cx++)
                for(int cy = 0; cy < 2; cy++)
                    dp[i][cx][cy] = INF;

        // Base case: when i = L
        dp[L][0][0] = 0;  // Valid end state
        // dp[L][1][0], dp[L][0][1], dp[L][1][1] remain INF as they're invalid

        // Build solution from highest bit to lowest
        for(int i = L-1; i >= 0; i--) {
            int bitX = (X >> i) & 1;
            int bitY = (Y >> i) & 1;
            
            // Try each state at current position
            for(int cx = 0; cx < 2; cx++) {
                for(int cy = 0; cy < 2; cy++) {
                    if(dp[i+1][cx][cy] == INF) continue;
                    
                    // Try both possible bit values (0 and 1)
                    for(int bit = 0; bit < 2; bit++) {
                        int sumX = bitX + bit + cx;
                        int sumY = bitY + bit + cy;
                        int A = sumX & 1;
                        int B = sumY & 1;
                        int ncx = sumX >> 1;
                        int ncy = sumY >> 1;
                        
                        // Skip if both A and B are 1
                        if(A == 1 && B == 1) continue;
                        
                        ll curr_val = dp[i+1][cx][cy];
                        ll new_val = ((ll)bit << i) + curr_val;
                        dp[i][ncx][ncy] = min(dp[i][ncx][ncy], new_val);
                    }
                }
            }
        }

        ll ans = dp[0][0][0];
        if(ans > LIMIT) {
            cout << -1 << "\n";
        } else {
            cout << ans << "\n";
        }
    }
    return 0;
}