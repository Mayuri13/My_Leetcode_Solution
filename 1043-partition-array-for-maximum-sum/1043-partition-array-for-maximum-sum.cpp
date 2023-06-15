class Solution {
public:
    int find(int i, vector<int>& arr, int k, vector<int>&dp){
        if(i==arr.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans = -1, mxVal = -1, len = 0;
        for(int j=i; j<arr.size() && j<i+k; j++){
            len++;
            mxVal = max(mxVal, arr[j]);
            int sum = mxVal*len + find(j+1,arr,k,dp);
            ans = max(ans,sum);
        }
        dp[i] = ans;
        return dp[i];
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n,-1);
        return find(0,arr,k,dp);
    }
};