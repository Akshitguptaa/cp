#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    vector<string> ans;
    
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        if (mp.size() == 1) {
            ans.push_back("NO");
        } else {
            if (s[0] != s[n-1]) {
                ans.push_back("YES");
            } else {
                ans.push_back("NO");
            }
        }
    }
    
    for (string result : ans) {
        cout << result << endl;
    }

    return 0;
}
