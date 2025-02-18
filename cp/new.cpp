#include <bits/stdc++.h>
using namespace std;

void func(vector<int>& A, int n)
{
    int x = 0;

    vector<int> temp(n);
    for (int i = 0; i < n - 1; i++) {
        if (A[i] > A[i + 1]) {
            x = i + 1;
            break;
        }
    }

    if (x == 0){
        return;
    }
    int i = 0, j = x, k = 0;
    while (i < x && j < n) {
        if (A[i] < A[j]){
            temp[k++] = A[i++];
        }
        else{
            temp[k++] = A[j++];
        }
    }

    while (i < x){
        temp[k++] = A[i++];
    }
    while (j < n){
        temp[k++] = A[j++];
    }

    for (int i = 0; i < n; i++){
        A[i] = temp[i];
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    
    func(A, n);
    
    for(auto i:A){
        cout<<i<<" ";
    }   

    return 0;
}
