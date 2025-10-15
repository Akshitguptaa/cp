#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;



int s,e;
int n;

vector<pair<int,int>>v;

vector<vector<int>>adj(102);

int recc(int i,int j,int prev){
	// cout<<i<<" "<<j<<endl;
	if(i>=n||i>s)return 1e9;
	if(j>=2*(i+1)-1||j<0)return 1e9;
	if(s==i&&e==j){
		return 0;
	}
	
	int num=adj[i][j];
	int l,r,d;
	for(int k=0;k<=1;k++){
		if(v[k].first==num){
			d=v[k].second;
			if(j%2==0){
				l=v[1-k].first;
				r=v[1-k].second;
			}
			else{
				r=v[1-k].first;
				l=v[1-k].second;
			}
		}
		else if(v[k].second==num){
			d=v[k].first;
			if(j%2){
				l=v[1-k].first;
				r=v[1-k].second;
			}
			else{
				r=v[1-k].first;
				l=v[1-k].second;
			}
		}		
	}
	// cout<<i<<" "<<j<<" "<<l<<" "<<d<<" "<<r<<endl;
	
	//neeche ke liye
	int ans=1e9;
	ans=min(ans,1+recc(i+1,j+1,0));
	//left
	if(prev!=1)ans=min(ans,1+recc(i,j-1,2));
	
	//right
	if(prev!=2)ans=min(ans,1+recc(i,j+1,1));
	return ans;
}

void solve() {
    v.push_back({4,2});
    v.push_back({3,1});
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<2*(i+1)-1;j++){
            int x;
            cin>>x;
            adj[i].push_back(x);
        }
    }	
    cin>>s>>e;
    s--;
    e--;
    cout<<s<<" "<<e<<endl;
    cout<<recc(0,0,0)<<endl;
	
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    // cin >> t;
    // while(t--)
     solve();
    return 0;
}