class Solution {
  
public:
    //Tabulation Solution
    
     int minCost(int n, vector<int>& cuts) {
         
         int c = cuts.size();
         cuts.insert(cuts.begin(),0);
         cuts.push_back(n);

         sort(cuts.begin(),cuts.end());
         vector<vector<int>> dp(c+2,vector<int>(c+2,0));
         for(int i=c; i>=1; i--){
             for(int j=i; j<=c; j++){
                 // if(i>j)
                 //     continue;
                 int minm = INT_MAX;
    
                    for(int ind=i; ind<=j; ind++){

                        int cost = cuts[j+1] - cuts[i-1] +  dp[i][ind-1] + dp[ind+1][j];
                        minm = min(minm, cost);
                    }
                 dp[i][j] = minm;
             }
         }
         return dp[1][c];
    }
    // Memoization solution
//   int helper(int i, int j, vector<int> &cuts,  vector<vector<int>> &dp){
    
    
//     if(i>j)
//         return 0;
        
//     if(dp[i][j]!=-1)
//         return dp[i][j];
    
//     int minm = INT_MAX;
    
//     for(int ind=i; ind<=j; ind++){
        
//         int cost = cuts[j+1] - cuts[i-1] +  helper(i,ind-1,cuts,dp) + helper(ind+1,j,cuts,dp);
//         minm = min(minm, cost);
        
//     }
    
//     return dp[i][j] = minm;
//   }

//     int minCost(int n, vector<int>& cuts) {
         
//          int c = cuts.size();
//          cuts.insert(cuts.begin(),0);
//          cuts.push_back(n);

//          sort(cuts.begin(),cuts.end());
//          vector<vector<int>> dp(c+1,vector<int>(c+1,-1));

//         return helper(1,c,cuts,dp);
//     }
};