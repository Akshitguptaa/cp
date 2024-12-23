#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct PowerUp {
    int position, value;
};

int minPowerUps(int n, int m, int L, const vector<pair<int, int>>& hurdles, const vector<PowerUp>& powerups) {
    // Step 1: Mark the blocked positions from the hurdles
    vector<bool> blocked(L + 1, false);
    for (auto& hurdle : hurdles) {
        for (int i = hurdle.first; i <= hurdle.second; ++i) {
            blocked[i] = true;
        }
    }

    // Step 2: Power-up collection mapping
    vector<int> powerUpAt(L + 1, 0);  // Store the total power-up values at each position
    for (auto& p : powerups) {
        powerUpAt[p.position] += p.value;
    }

    // Step 3: BFS setup
    queue<pair<int, int>> q;  // Queue of pairs: position, number of power-ups collected
    q.push({1, 0});  // Start at position 1 with 0 power-ups
    vector<bool> visited(L + 1, false);  // Visited array to avoid reprocessing positions
    visited[1] = true;

    // Step 4: BFS traversal
    while (!q.empty()) {
        int pos = q.front().first;
        int powerUpsCollected = q.front().second;
        q.pop();

        // If we've reached position L, return the result
        if (pos == L) {
            return powerUpsCollected;
        }

        // Current jump power is 1 + power-ups collected at this position
        int currentJumpPower = 1 + powerUpAt[pos];

        // Try all positions reachable from the current position
        for (int nextPos = pos + 1; nextPos <= min(pos + currentJumpPower, L); ++nextPos) {
            if (!blocked[nextPos] && !visited[nextPos]) {
                visited[nextPos] = true;
                // If we collect power-ups at the next position, increase the count
                q.push({nextPos, powerUpsCollected + (powerUpAt[nextPos] > 0 ? 1 : 0)});
            }
        }
    }

    // If we exhaust the queue without reaching L, return -1
    return -1;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, L;
        cin >> n >> m >> L;
        
        vector<pair<int, int>> hurdles(n);
        for (int i = 0; i < n; ++i) {
            cin >> hurdles[i].first >> hurdles[i].second;
        }
        
        vector<PowerUp> powerups(m);
        for (int i = 0; i < m; ++i) {
            cin >> powerups[i].position >> powerups[i].value;
        }
        
        cout << minPowerUps(n, m, L, hurdles, powerups) << endl;
    }
    
    return 0;
}
