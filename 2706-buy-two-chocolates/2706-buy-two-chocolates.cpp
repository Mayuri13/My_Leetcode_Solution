class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int cnt=0, temp = money;
        for(int i=0; i<2; i++){
            if(prices[i]<=temp){
                temp -= prices[i];
                cnt++;
            }
            else
                break;
        }
        if(cnt!=2)
            return money;
        return temp;
    }
};