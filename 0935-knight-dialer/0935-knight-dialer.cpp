class Solution {
public:
    int di[8] = {2,2,-2,-2,1,1,-1,-1};
    int dj[8] = {1,-1,1,-1,2,-2,2,-2};
    int mod = 1e9+7;
    
    int find(int i, int j, vector<vector<vector<int>>>&dp, vector<vector<int>>&phn, int n){
        if(phn[i][j]==-1)
            return 0;
        if(n==0)
            return 1;
        if(dp[i][j][n]!=-1) return dp[i][j][n];
        int pick = 0;
        for(int k=0; k<8; k++){
            int ni = i + di[k];
            int nj = j + dj[k];
            if(ni<4 && ni>=0 && nj<3 && nj>=0 && phn[ni][nj]!=-1){
                pick = (pick + find(ni,nj,dp,phn,n-1))%mod;
            }
        }
        dp[i][j][n] = pick;
        return dp[i][j][n];
    }
    
    int knightDialer(int n) {
        vector<vector<int>>phn(4,vector<int>(3));
        vector<vector<vector<int>>>dp(4,vector<vector<int>>(3,vector<int>(n,-1)));
        int it = 1;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                phn[i][j] = it;
                it++;
            }
        }
        phn[3][0] = -1; phn[3][1] = 0; phn[3][2] = -1;
        int res=0;
        for(int i=0; i<4; i++){
            for(int j=0; j<3; j++){
                if(phn[i][j]==-1) continue;
                res = (res + find(i,j,dp,phn,n-1))%mod;
            }
        }
        return res;
    }
};