class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,-1)), vis(n,vector<int>(m,0));
        queue < pair < pair < int, int > , int >> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int DX[4] = {-1, 1, 0, 0};
        int DY[4] = {0, 0, -1, 1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            ans[r][c] = dis;
            for(int i = 0; i < 4; i++){
                int cx = r + DX[i];
                int cy = c + DY[i];

                // Check if the neighboring cell is within the grid boundaries and has a greater value
                if (cx >= 0 && cx < n && cy >= 0 && cy < m && mat[cx][cy]==1 && vis[cx][cy]!=1) {
                    q.push({{cx,cy},dis+1});
                    vis[cx][cy]=1;
                }
            }
        }
        
        return ans;
    }
};