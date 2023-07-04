class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        sort(nums.begin(),nums.end());
        int i=0, j=2;
        while(i<nums.size() && j<nums.size()){
            if(nums[i]!=nums[j])
                return nums[i];
            else{
                i = j+1;
                j = i+2;
            }
        }
        return nums[i];
    }
};