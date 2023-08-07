class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int r = mat.size(); 
        int c = mat[0].size();
        int n = r*c;
        int s = 0, e = n-1;
        while(s<=e){
            int mid = e - (e - s)/2;
            int i = mid/c, j = mid%c;
            if(mat[i][j] > target)
                e = mid-1;
            else if(mat[i][j] < target)
                s = mid+1;
            else
                return true;
        }
        return false;
    }
};