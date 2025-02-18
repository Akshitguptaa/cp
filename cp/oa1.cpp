#include<bits/stdc++.h>
using namespace std;

vector<int> row = {-1, 1, 0, 0};
vector<int> col = {0, 0, 1, -1};

void bfs(vector<string> &v, int i, int j, vector<vector<bool>> &vis, set<pair<int, int>> &vec) {
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true;
    vec.insert({i, j});

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int r1 = r + row[k];
            int c1 = c + col[k];
            if (r1 >= 0 && c1 >= 0 && r1 < v.size() && c1 < v[0].size()) {
                if (v[r1][c1] == '1' && !vis[r1][c1]) {
                    vis[r1][c1] = true;
                    vec.insert({r1, c1});
                    q.push({r1, c1});
                }
            }
        }
    }
}

int countMatches(vector<string> grid1, vector<string> grid2) {
    int n = grid1.size();
    int m = grid1[0].size();
    vector<vector<bool>> vis1(n, vector<bool>(m, false));
    vector<vector<bool>> vis2(n, vector<bool>(m, false));
    vector<set<pair<int, int>>> vecs1, vecs2;

    // Find all vecs in grid1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis1[i][j] && grid1[i][j] == '1') {
                set<pair<int,int>> vec;
                bfs(grid1, i, j, vis1, vec);
                vecs1.push_back(vec);
            }
        }
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (!vis2[i][j] && grid2[i][j] == '1') {
                set<pair<int,int>> vec;
                bfs(grid2, i, j, vis2, vec);
                vecs2.push_back(vec);
            }
        }
    }

    int c=0;
    for(auto i:vecs2) {
        for(auto j : vecs1){
            if (j == i) {
                c++;
                break;
            }
        }
    }

    return c;
}
int main (){
    vector<string> grid2 = {"1001", "0011", "1000","0000"};
    vector<string> grid1 = {"1101", "0011", "1100","0100"};
    cout << "Number of matching vecs: " << countMatches(grid1, grid2) << endl;
}