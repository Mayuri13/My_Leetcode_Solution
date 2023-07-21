class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& vis){
        vis[r][c] = 1;
        for(int i=0; i<4; i++){
                int nr = r+dx[i];
                int nc = c+dy[i];
                if(nr < grid.size() && nr>=0 && nc<grid[0].size() && nc>=0 && grid[nr][nc]=='1'
                   && !vis[nr][nc]){
                    dfs(nr,nc,grid,vis);
                }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans=0;
        vector<vector<int>>vis(m, vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(i,j,grid,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};