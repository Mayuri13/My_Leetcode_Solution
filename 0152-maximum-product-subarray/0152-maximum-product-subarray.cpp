class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //Finding prefix and suffix multiplications, for each elements
        int prefix = 1, suffix = 1, n = nums.size(), ans = INT_MIN;
        for(int i=0; i<n; i++){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
            prefix *= nums[i];
            suffix *= nums[n-i-1];
            ans = max(ans, max(prefix, suffix));
        }
        return ans;
    }
};