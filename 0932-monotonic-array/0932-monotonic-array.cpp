class Solution {
public:
    bool desc(vector<int>&nums){
      for(int i=1; i<nums.size(); i++){
        if(nums[i]>nums[i-1]) return false;
      }
      return true;
    }
    bool incr(vector<int>&nums){
      for(int i=1; i<nums.size(); i++){
        if(nums[i]<nums[i-1]) return false;
      }
      return true;
    }
    bool isMonotonic(vector<int>& nums) {
      return desc(nums) || incr(nums); 
    }
};