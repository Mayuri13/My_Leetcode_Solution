//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>> &grid){
        vis[r][c] = 1;
        for(int i=0; i<4; i++){
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc] == 1 && !vis[nr][nc]){
                dfs(nr,nc,vis,grid);
            }
        }
    }
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int j=0; j<m; j++){
            if(!vis[0][j] && grid[0][j] == 1){
                dfs(0,j,vis,grid);
            }
            if(!vis[n-1][j] && grid[n-1][j] == 1){
                dfs(n-1,j,vis,grid);
            }
        }
        for(int i=0; i<n; i++){
            if(!vis[i][0] && grid[i][0] == 1){
                dfs(i,0,vis,grid);
            }
            if(!vis[i][m-1] && grid[i][m-1] == 1){
                dfs(i,m-1,vis,grid);
            }
        }
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(!vis[i][j] && grid[i][j] == 1) ans++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends