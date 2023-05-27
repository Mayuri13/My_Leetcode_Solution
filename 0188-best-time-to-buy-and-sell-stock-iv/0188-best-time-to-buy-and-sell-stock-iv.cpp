class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>prev(2,vector<int>(k+1,0)), curr(2,vector<int>(k+1,0));
        for(int i=n-1; i>=0; i--){
            for(int j=1; j>=0; j--){
                for(int l=1; l<=k; l++){
                    if(j){
                        curr[j][l]= max((-prices[i]+prev[0][l]),(0+prev[1][l]));
                    }
                    else{
                        curr[j][l]= max((prices[i]+prev[1][l-1]),(0+prev[0][l]));
                    }
                }
            }
            prev = curr;
        }
        return prev[1][k];
    }
};