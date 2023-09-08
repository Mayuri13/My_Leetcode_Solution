class Solution {
public:
    vector<vector<int>> generate(int r) {
        vector<vector<int>>ans(r);
        vector<int>f = {1};
        ans[0] = f;
        for(int i=1; i<r; i++){
            vector<int>tmp(i+1);
            tmp[0] = 1;
            tmp[i] = 1;
            for(int j=1; j<i; j++){
                tmp[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans[i] = tmp;
        }
        return ans;
    }
};