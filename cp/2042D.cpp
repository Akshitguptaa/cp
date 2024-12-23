#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        cin >> n; // Number of users

        vector<pair<pair<int, int>, int>> users(n); // stores (li, ri, index)
        
        // Reading the intervals
        for (int i = 0; i < n; ++i) {
            cin >> users[i].first.first >> users[i].first.second;
            users[i].second = i; // Store the original index of the user
        }

        // Sort users by the first element of the pair (li)
        sort(users.begin(), users.end(), [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
            return a.first.first < b.first.first; // Sort by li
        });

        // Array to store the result (strongly recommended tracks) for each user
        vector<int> result(n, 0);

        // To calculate strongly recommended tracks for each user
        for (int i = 0; i < n; ++i) {
            int li = users[i].first.first;
            int ri = users[i].first.second;

            int maxL = -1; // Max `li` of predictors
            int minR = 1000000000; // Min `ri` of predictors
            bool hasPredictors = false;

            // Find all users that can be predictors
            for (int j = 0; j < n; ++j) {
                if (users[j].first.first <= li && users[j].first.second >= ri) {
                    maxL = max(maxL, users[j].first.first); // Update maxL (start of range)
                    minR = min(minR, users[j].first.second); // Update minR (end of range)
                    hasPredictors = true;
                }
            }

            // If valid predictors exist, calculate the strongly recommended tracks
            if (hasPredictors && maxL <= minR) {
                // The strongly recommended tracks are in the range [maxL, minR] 
                // but not in the range [li, ri] that user i likes.
                int recommendedTracks = max(0, minR - maxL + 1 - (ri - li + 1));
                result[users[i].second] = recommendedTracks;
            }
        }

        // Output the result for the current test case
        for (int i = 0; i < n; ++i) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
