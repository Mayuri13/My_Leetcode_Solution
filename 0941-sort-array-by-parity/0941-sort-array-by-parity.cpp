class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int ev = 0, od = 0;
        while(ev < nums.size() && od < nums.size()){
            if(nums[od]%2 == 0){
                swap(nums[ev], nums[od]);
                ev++;
                od++;
            }
            else
                od++;
        }
        return nums;
    }
};