class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size()==1 || nums.size()==2)
            return -1;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];
    }
};