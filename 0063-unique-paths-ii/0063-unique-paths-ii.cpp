class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m][n];
        int up=0, left=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                up=0,left=0;
                 if(obstacleGrid[i][j]!=1){
                        if(i==0 && j==0) dp[i][j]=1;
                        else{
                            if(i>0) up = dp[i-1][j];
                            if(j>0) left = dp[i][j-1];
                            dp[i][j] = up + left;
                        }
                    }
                    else
                        dp[i][j]=0;   
                }
            }
        return dp[m-1][n-1];
    }
};