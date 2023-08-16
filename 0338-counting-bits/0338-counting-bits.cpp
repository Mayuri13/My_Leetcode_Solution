class Solution {
public:
    vector<int> countBits(int n) {
        //Using DP and right shift concept
        vector<int>dp(n+1);
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            if(i%2==0)
                dp[i] = dp[i/2];
            else{
                dp[i] = dp[i/2] + 1;
            }
        }
        return dp;
        //Using normal bit manipulation
        
        // vector<int>ans(n+1,0);
        // for(int i=1; i<=n; i++){
        //     if((i&(i-1))==0){
        //         ans[i]=1;
        //         continue;
        //     }
        //     int cnt=0, j=i;
        //     while(j>0){
        //         j = j&(j-1);
        //         cnt++;
        //     }
        //     ans[i] = cnt;
        // }
        // return ans;
    }
};