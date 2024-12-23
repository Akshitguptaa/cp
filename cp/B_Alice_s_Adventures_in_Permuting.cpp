#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    
    while (t--) {
        ll n, b, c;
        cin >> n >> b >> c;
        
        // Case 1: When b = 0, all elements are the same and equal to `c`
        if (b == 0) {
            if (c >= n) {
                cout << -1 << endl;
            } else {
                cout << 0 << endl;  // No operations needed, array already a permutation
            }
            continue;
        }
        
        // Case 2: When b > 0, check if it's possible to form a permutation
        ll max_val = b * (n - 1) + c;
        
        // If the largest value in the array exceeds n-1, it's impossible to form a permutation
        if (max_val >= n) {
            cout << -1 << endl;
            continue;
        }
        
        // Now we simulate the operation process
        ll operations = 0;
        ll current_mex = 0;  // The smallest missing number to form a valid permutation
        
        // Calculate the number of operations needed to reach the valid permutation
        while (current_mex < n) {
            ll new_max = b * (n - 1) + c;
            if (new_max < current_mex) {
                break;
            }

            ll x = new_max - current_mex;
            operations += x;
            current_mex += x;
        }
        
        cout << operations << endl;
    }
    return 0;
}
