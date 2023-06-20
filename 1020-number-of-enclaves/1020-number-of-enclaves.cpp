class Solution {
public:
    int DX[4] = {-1, 1, 0, 0};
    int DY[4] = {0, 0, -1, 1};
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<int>>& grid){
        vis[r][c] = 1;
        for(int i = 0; i < 4; i++){
            int cx = r + DX[i];
            int cy = c + DY[i];
            if (cx >= 0 && cx < grid.size() && cy >= 0 && cy < grid[0].size() 
                && vis[cx][cy]!=1 && grid[cx][cy]==1) {
                dfs(cx,cy,vis,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j = 0 ; j<m;j++) {
            // check for unvisited Os in the boundary rows
            // first row 
            if(!vis[0][j] && grid[0][j] == 1) {
                dfs(0, j, vis, grid); 
            }
            
            // last row 
            if(!vis[n-1][j] && grid[n-1][j] == 1) {
                dfs(n-1,j,vis,grid); 
            }
        }
        
        for(int i = 0;i<n;i++) {
            // check for unvisited Os in the boundary columns
            // first column 
            if(!vis[i][0] && grid[i][0] == 1) {
                dfs(i, 0, vis, grid); 
            }
            
            // last column
            if(!vis[i][m-1] && grid[i][m-1] == 1) {
                dfs(i, m-1, vis, grid); 
            }
        }
        int ans = 0;
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(!vis[i][j] && grid[i][j]==1)
                    ans++;
            }
        }
        return ans;
    }
};