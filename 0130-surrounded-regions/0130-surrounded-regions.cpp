class Solution {
public:
    int DX[4] = {-1, 1, 0, 0};
    int DY[4] = {0, 0, -1, 1};
    void find(int r, int c, vector<vector<char>>& b, vector<vector<int>>& vis){
        vis[r][c] = 1;
        for(int i = 0; i < 4; i++){
            int cx = r + DX[i];
            int cy = c + DY[i];
            if (cx >= 0 && cx < b.size() && cy >= 0 && cy < b[0].size() && vis[cx][cy]!=1 && b[cx][cy]=='O') {
                find(cx,cy,b,vis);
            }
        }
    }
    
    void solve(vector<vector<char>>& b) {
        int m = b.size(), n = b[0].size();
        vector<vector<int>>vis(m,vector<int>(n,-1));
        //Marked all boundary vectors as visied
        for(int i=0; i<m; i++){
            if(b[i][0]=='O'){
                find(i,0,b,vis);
            }
            else
                vis[i][0] = 1;
            
            if(b[i][n-1]=='O'){
                find(i,n-1,b,vis);
            }
            else{
                vis[i][n-1] = 1;
            }
        }
        for(int i=0; i<n; i++){
            if(b[0][i]=='O'){
                find(0,i,b,vis);
            }
            else
                vis[0][i] = 1;
            
            if(b[m-1][i]=='O'){
                find(m-1,i,b,vis);
            }
            else{
                vis[m-1][i] = 1;
            }
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(vis[i][j]==-1 && b[i][j]=='O'){
                    b[i][j]='X';
                }
            }
        }
    }
};