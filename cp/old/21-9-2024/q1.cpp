#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t; 
    while (t--) {
        int n, k;
        cin >> n;
        cin >> k; 
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int x = 0;
        int y = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] >= k) {
                x += a[i];
            } else if (a[i] == 0) {
                if (x > 0) {
                    x--;
                    y++;
                }
            }
        }
        cout << y << endl;
    }

    return 0;
}
