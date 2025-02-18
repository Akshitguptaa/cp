#include<bits/stdc++.h>
using namespace std;

int deleteProducts(vector<int> ids,int m){
    int n= ids.size();
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[ids[i]]++;
    }

    vector<int> v;
    for(auto i:mp){
        if(i.second!=0){
        v.push_back(i.second);
        }
    }

    sort(v.begin(),v.end());
    int c=v.size();
    for(int i=0;i<v.size();i++){
        if (m>=v[i]){
            m-=v[i]; 
            c--; 
        }else{
            break;
        }
    }
    return c;
}

int main(){
    // deleteProducts()
    vector<int> ids1 = {1, 1,3,1,2,2};
    int m1 = 3;
    cout << "Remaining products after deletion (Test 1): " << deleteProducts(ids1, m1) << endl;

    // Test 2: Deleting all products (m is large enough)
    vector<int> ids2 = {5, 5, 6, 6, 7, 7, 7};
    int m2 = 100;  // Large enough to delete all products
    cout << "Remaining products after deletion (Test 2): " << deleteProducts(ids2, m2) << endl;

    // Test 3: No products to delete (m is 0)
    vector<int> ids3 = {8, 8, 9, 9};
    int m3 = 0;
    cout << "Remaining products after deletion (Test 3): " << deleteProducts(ids3, m3) << endl;

    // Test 4: m is smaller than all frequencies
    vector<int> ids4 = {10, 10, 10, 11, 12};
    int m4 = 2;
    cout << "Remaining products after deletion (Test 4): " << deleteProducts(ids4, m4) << endl;

    // Test 5: Single product case
    vector<int> ids5 = {13};
    int m5 = 1;
    cout << "Remaining products after deletion (Test 5): " << deleteProducts(ids5, m5) << endl;


}