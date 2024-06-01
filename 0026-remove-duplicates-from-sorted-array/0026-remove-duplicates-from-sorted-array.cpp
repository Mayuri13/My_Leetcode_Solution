class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         int i = 0, j = 1;
         while(j < nums.size()){
            if(nums[i] == nums[j]){
                j++;
            }
            else{
                nums[i+1] = nums[j];
                i++;
                j++;
            }
         }
        return i+1;
    }
};