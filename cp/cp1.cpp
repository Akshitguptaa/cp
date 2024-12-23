#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Person {
    int s1, s2, s3;
};

// Function to check if person `a` is strictly better than person `b`
bool is_better(const Person &a, const Person &b) {
    return (a.s1 <= b.s1 && a.s2 <= b.s2 && a.s3 <= b.s3) &&
           (a.s1 < b.s1 || a.s2 < b.s2 || a.s3 < b.s3);
}

void solve() {
    int T;
    cin >> T;
    while (T--) {
        // Read scores for three people
        vector<Person> people(3);
        for (int i = 0; i < 3; ++i) {
            cin >> people[i].s1 >> people[i].s2 >> people[i].s3;
        }
        
        // Try to order the people in a way that satisfies the condition
        sort(people.begin(), people.end(), [](const Person &a, const Person &b) {
            return tie(a.s1, a.s2, a.s3) < tie(b.s1, b.s2, b.s3);
        });
        
        // Check if sorted order satisfies the strictly better condition
        if (is_better(people[0], people[1]) && is_better(people[1], people[2])) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
