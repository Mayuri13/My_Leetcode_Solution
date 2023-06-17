class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        int ncolor = image[sr][sc];
        if(ncolor == color)
            return image;
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc] = 1;
        image[sr][sc] = color;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1}; 
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
          // neighbouring row and column
              int nrow = r + drow[i];
              int ncol = c + dcol[i];
              // check for valid cell and 
              // then for unvisited fresh orange
              if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                vis[nrow][ncol] == 0 && image[nrow][ncol] == ncolor) {
                image[nrow][ncol] = color;
                q.push({nrow, ncol}); 
                vis[nrow][ncol] = 1;
              }
            }
        }
        
        return image;
    }
};