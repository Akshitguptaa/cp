#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int func(int n,vector<int>& a) {
    int maxx = 0,count = 0;

    for (int i = 0; i < n; i=i+2) { 
        maxx = max(maxx, a[i]);
        count++;
    }

    int first = 0;
    int second = 0;
    for (int i = 1; i < n; i += 2) { 
        first = max(first, a[i]);
        second++;
    }

    return max(maxx + count,  first + second);
}

int main() {
    int t;
    cin >> t;  

    while (t--) {
        int n;
        cin >> n;  
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];  
        }
        
        cout << func(n, a) << endl;  
    }

    return 0;
}
