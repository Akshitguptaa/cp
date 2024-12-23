#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> freq(26, 0);
    
    for (char c : s) {
        freq[c - 'a']++;
    }
    
    string even, odd;

    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 0) {
            string chars(freq[i], 'a' + i);
            if (even.size() <= odd.size()) {
                even += chars;
            } else {
                odd += chars;
            }
        }
    }

    string result;
    int i = 0, j = 0;
    while (i < even.size() || j < odd.size()) {
        if (i < even.size()) result += even[i++];
        if (j < odd.size()) result += odd[j++];
    }

    cout << result << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}