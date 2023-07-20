class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        vector<pair<int,int>>pos;
        int n = mat.size(), m = mat[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    pos.push_back({i,j});
                }
            }
        }
        for(int i=0; i<pos.size(); i++){
            int r = pos[i].first, c = pos[i].second;
            for(int col = 0; col<m; col++)
                mat[r][col] = 0;
            for(int row = 0; row<n; row++)
                mat[row][c] = 0;
        }
    }
};