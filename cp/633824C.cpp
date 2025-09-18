#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int v[1005][2];
int arr[1005];
int n,m;

vector<int>res;
set<int>st;
int recc(int i,int flg,int end){
	if(i>=end)return 0;
	int cnt=flg;
	int s=v[i][0],e=v[i][1];
	int tmp=0;
	for(int j=0;j<m;j++){
			if(arr[j]>=s&&arr[j]<=e)cnt++;
			if(e==arr[j])tmp=1;
		}
	
	if(cnt>=3){
		return 1e6;
	}
	else if(cnt==0){		
		if(!tmp){
		if(recc(i+1,1,end)<=recc(i+1,0,end)){
			
			for(int j=s;j<=s+10;j++){
				if(st.find(j)==st.end()){
				res.push_back(j);
				st.insert(j);
				break;
				}
			}
			res.push_back(e);
			return 2+recc(i+1,1,end);			
		}
		else{
			for(int j=s;j<=s+10;j++){
				if(st.find(j)==st.end()){
				res.push_back(j);
				st.insert(j);
				break;
				}
			}
			for(int j=s;j<=s+10;j++){
				if(st.find(j)==st.end()){
				res.push_back(j);
				st.insert(j);
				break;
				}
			}
			return 2+recc(i+1,0,end);				
		}
	}
	else{
		for(int j=s;j<=s+10;j++){
				if(st.find(j)==st.end()){
				res.push_back(j);
				st.insert(j);
				break;
				}
			}
			for(int j=s;j<=s+10;j++){
				if(st.find(j)==st.end()){
				res.push_back(j);
				st.insert(j);
				break;
				}
			}
			return 2+recc(i+1,0,end);				
	}
}
	else if(cnt==1){
		
	if(!tmp){
		if(recc(i+1,1,end)<=recc(i+1,0,end)){
			res.push_back(e);
			return 1+recc(i+1,1,end);			
			
		}
		else{
			for(int j=s;j<=s+10;j++){
				if(st.find(j)==st.end()){
				res.push_back(j);
				st.insert(j);
				break;
				}
			}
			return 1+recc(i+1,0,end);					
		}
	}
	else{
		for(int j=s;j<=s+10;j++){
				if(st.find(j)==st.end()){
				res.push_back(j);
				st.insert(j);
				break;
				}
			}
			return 1+recc(i+1,0,end);					
		}
	}
	else return recc(i+1,0,end);
}
void solve() {
	cin>>n;	
	for(int i=0;i<n;i++){
		cin>>v[i][0];
		cin>>v[i][1];
	}
	cin>>m;
	
	for(int i=0;i<m;i++)cin>>arr[i];
	for(int i=0;i<m;i++)st.insert(arr[i]);
	
	//chk
	for(int i=0;i<n;i++){
		int s=v[i][0],e=v[i][1];
		
		int cnt=0;
		for(int j=0;j<m;j++){
			if(arr[j]>=s&&arr[j]<=e)cnt++;
		}
		if(cnt>=3){
			cout<<"impossible"<<endl;
			return;
		}
	}
	// 
	int start_of_block = 0;
	for(int i=1; i<n; i++){
		if(v[i][0] != v[i-1][1]){ // If there's a gap, a block ends
			recc(start_of_block, 0, i);
			start_of_block = i;
		}
	}
	// Process the last block
	recc(start_of_block, 0, n);
	cout<<res.size()<<endl;
    
	for(auto it:res)cout<<it<<" ";
	cout<<endl;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    // cin >> t;
    // while (t--) 
    solve();
    return 0;
}