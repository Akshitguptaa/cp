#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Interval {
    int start, end, index;
};

bool compareByStart(const Interval &a, const Interval &b) {
    return a.start < b.start;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<Interval> intervals(n);
        
        // Reading intervals
        for (int i = 0; i < n; ++i) {
            cin >> intervals[i].start >> intervals[i].end;
            intervals[i].index = i;  // Store original index for output purposes
        }

        // Sort intervals by their start time
        sort(intervals.begin(), intervals.end(), compareByStart);

        // To store the color of each interval
        vector<int> color(n);
        
        // Using a set to keep track of end times and the associated colors
        set<pair<int, int>> activeIntervals;  // stores (end time, color)
        int maxColors = 0;  // Tracks the maximum number of overlaps
        
        // Sweep line algorithm: process intervals
        for (int i = 0; i < n; ++i) {
            // Remove all intervals that have ended before the current one starts
            while (!activeIntervals.empty() && activeIntervals.begin()->first < intervals[i].start) {
                activeIntervals.erase(activeIntervals.begin());
            }

            // Assign color to the current interval
            int colorAssigned = 1;
            if (!activeIntervals.empty()) {
                // Find the first color not used by the currently active intervals
                set<int> usedColors;
                for (auto it : activeIntervals) {
                    usedColors.insert(it.second);
                }
                // Find the smallest color not used
                while (usedColors.count(colorAssigned)) {
                    ++colorAssigned;
                }
            }
            // Assign the chosen color to the current warrior's interval
            color[intervals[i].index] = colorAssigned;
            activeIntervals.insert({intervals[i].end, colorAssigned});

            // Update the maximum number of colors needed
            maxColors = max(maxColors, (int)activeIntervals.size());
        }

        // Output the result for the current test case
        cout << maxColors << endl;
        for (int i = 0; i < n; ++i) {
            cout << color[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
