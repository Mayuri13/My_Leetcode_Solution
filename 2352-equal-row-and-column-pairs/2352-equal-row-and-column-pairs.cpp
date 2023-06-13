class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0; i<grid.size(); i++){
            vector<int>row = grid[i];
            for(int j=0; j<grid[i].size(); j++){
                vector<int> col;
                for(int k=0; k<grid.size(); k++){
                    col.push_back(grid[k][j]);
                }
                if(row==col)
                    ans++;
            }
        }
        return ans;
    }
};