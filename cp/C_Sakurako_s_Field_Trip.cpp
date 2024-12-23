#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int minimalDisturbance(int n, const vector<int>& topics) {
    unordered_map<int, int> freq;
    
    // Count frequency of each topic
    for (int topic : topics) {
        freq[topic]++;
    }
    
    // Determine the maximum frequency of any topic
    int max_freq = 0;
    for (const auto& entry : freq) {
        max_freq = max(max_freq, entry.second);
    }
    
    // The minimal possible disturbance is calculated as:
    // disturbance = (n - max_freq)
    // This represents how many positions can be filled without causing disturbance.
    return max(0, n - max_freq);
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> topics(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> topics[i];
        }
        
        cout << minimalDisturbance(n, topics) << endl;
    }
    
    return 0;
}
