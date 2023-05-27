class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = 0, b = prices[0];
        for(int i=1; i<prices.size(); i++){
            if(prices[i]<b){
                b = prices[i];
            }
            mx = max(mx, prices[i]-b);
        }
        return mx;
    }
};