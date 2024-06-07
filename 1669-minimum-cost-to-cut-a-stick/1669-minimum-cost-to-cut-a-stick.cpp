class Solution {
public:
//Tabultaion Solution
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();

        //Insert n at back of cuts and 0 at front of cuts
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        //sort cuts vector, so that we can solve the problem independently
        sort(cuts.begin(), cuts.end());

        //For DP Solution, as only i and j are changing, so 2d DP
        vector<vector<int>>dp(c+2, vector<int>(c+2, 0));

        //Here, i = 1 to c and j = c to 1
        for(int i=c; i>=1; i--){
            for(int j=1; j<=c; j++){
                if(i > j) continue;
                int mini = INT_MAX, cost = 0;
                for(int idx = i; idx <= j; idx++){
                    cost = cuts[j+1] - cuts[i-1] + dp[i][idx-1] + dp[idx+1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }



// Memoization Solution
    // int find(int i, int j, vector<int>& cuts, vector<vector<int>>&dp){
    //     if(i > j) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];

    //     //mini is for finding the minimum cost possible by trying each and every order of cuts
    //     int mini = INT_MAX, cost = 0;
    //     for(int idx = i; idx <= j; idx++){
    //         cost = cuts[j+1] - cuts[i-1] + find(i, idx-1, cuts, dp) + find(idx+1, j, cuts, dp);
    //         mini = min(mini, cost);
    //     }
    //     dp[i][j] = mini;
    //     return dp[i][j];
    // }

    // int minCost(int n, vector<int>& cuts) {
    //     int c = cuts.size();

    //     //Insert n at back of cuts and 0 at front of cuts
    //     cuts.push_back(n);
    //     cuts.insert(cuts.begin(), 0);

    //     //sort cuts vector, so that we can solve the problem independently
    //     sort(cuts.begin(), cuts.end());

    //     //For DP Solution, as only i and j are changing, so 2d DP
    //     vector<vector<int>>dp(c+1, vector<int>(c+1, -1));

    //     //Range of computing is 1 to c, bcz 0 and n is used for calculating the size of the rod
    //     return find(1,c,cuts,dp);
    // }
};