#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    vector<int> b(m);
    
    unordered_map<int, int> countA, countB;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        countA[a[i]]++;
    }
    
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        countB[b[i]]++;
    }
    
    // Max heap to process the target numbers in descending order
    priority_queue<int> pq;
    
    // Add all elements of b to the priority queue
    for (const auto& entry : countB) {
        pq.push(entry.first);
    }
    
    // Convert the priority queue to a vector for iteration
    vector<int> targets;
    while (!pq.empty()) {
        targets.push_back(pq.top());
        pq.pop();
    }

    // Process each number from b
    for (int target : targets) {
        while (countB[target] > 0) {
            // Try to match target in a
            if (countA[target] > 0) {
                countA[target]--;
                countB[target]--;
            } else {
                // We cannot directly match, try to split a larger number
                if (countA[target + 1] > 0) {
                    countA[target + 1]--;
                    countA[target]++;
                    countB[target]--;
                } else if (countA[target - 1] > 0) {
                    countA[target - 1]--;
                    countA[target]++;
                    countB[target]--;
                } else {
                    cout << "No" << endl;
                    return;
                }
            }
        }
    }
    
    // If we matched all elements in b, the answer is "Yes"
    cout << "Yes" << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
