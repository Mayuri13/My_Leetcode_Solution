class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0)
            return -1;
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        dist[0][0]=1;
        queue<pair<int,int>>q;
        q.push({0,0});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    int nx = r+i, ny = c+j;
                    if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0 && 1+dist[r][c]<dist[nx][ny]){
                        dist[nx][ny]=1+dist[r][c];
                        q.push({nx,ny});
                    }
                }
            }
        }
        if(dist[n-1][n-1]==1e9)
            return -1;
        return dist[n-1][n-1];
    }
};