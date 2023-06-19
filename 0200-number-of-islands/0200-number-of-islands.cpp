class Solution {
public:
    int DX[4] = {-1, 1, 0, 0};
    int DY[4] = {0, 0, -1, 1};
    void find(int x, int y, vector<vector<char>>& grid, vector<vector<int>>& vis){
        
        vis[x][y]=1;
        for (int i = 0; i < 4; i++) {
            int cx = x + DX[i];
            int cy = y + DY[i];
            
            // Check if the neighboring cell is within the grid boundaries and has a greater value
            if (cx >= 0 && cx < grid.size() && cy >= 0 && cy < grid[0].size() 
                && grid[cx][cy]=='1' && vis[cx][cy]!=1) {
                find(cx, cy, grid, vis);
            }
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans=0;
        vector<vector<int>>vis(n,vector<int>(m,-1));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==-1 && grid[i][j]=='1'){
                    find(i,j,grid,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};