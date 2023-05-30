class Solution {
public:
    //Tracing the LIS(In 1D DP)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), mx = 1;
        vector<int>dp(n,1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i])
                    dp[i] = max(dp[i], 1+dp[j]);
                mx = max(mx,dp[i]);
            }
        }
        return mx;
    }
    
    
    //Space Optimization Solution
//     int lengthOfLIS(vector<int>& arr) {
//         int n = arr.size();
//         vector<int>prev(n+1,0), curr(n+1,0);
    
//         for(int ind = n-1; ind>=0; ind --){
//             for (int prev_index = ind-1; prev_index >=-1; prev_index --){

//                 int notTake = 0 + prev[prev_index +1];

//                 int take = 0;

//                 if(prev_index == -1 || arr[ind] > arr[prev_index]){

//                     take = 1 + prev[ind+1];
//                 }

//                 curr[prev_index+1] = max(notTake,take);

//             }
//             prev = curr;
//         }
    
//     return prev[0];
//     }
    
//     //Tabulation Solution
//     int lengthOfLIS(vector<int>& arr) {
//         int n = arr.size();
//         vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
//         for(int ind = n-1; ind>=0; ind --){
//             for (int prev_index = ind-1; prev_index >=-1; prev_index --){

//                 int notTake = 0 + dp[ind+1][prev_index +1];

//                 int take = 0;

//                 if(prev_index == -1 || arr[ind] > arr[prev_index]){

//                     take = 1 + dp[ind+1][ind+1];
//                 }

//                 dp[ind][prev_index+1] = max(notTake,take);

//             }
//         }
    
//     return dp[0][0];
//     }
    
    //Memoization Solution
    // int find(int i, int prev, vector<vector<int>>&dp, vector<int>&nums){
    //     if(i==nums.size())
    //         return 0;
    //     if(dp[i][prev+1]!=-1)
    //         return dp[i][prev+1];
    //     int p=0;
    //     if((prev == -1) || (nums[prev]<nums[i]))
    //         p = 1+find(i+1,i,dp,nums);
    //     int np = find(i+1,prev,dp,nums);
    //     dp[i][prev+1] = max(p,np);
    //     return dp[i][prev+1];
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<vector<int>>dp(n,vector<int>(n,-1));
    //     return find(0,-1,dp,nums);
    // }
};