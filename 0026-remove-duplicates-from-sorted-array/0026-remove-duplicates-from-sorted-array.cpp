class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //Most optimal solution
         int i = 0, j = 1;
         while(j < nums.size()){
            if(nums[i] == nums[j]){
                j++;
            }
            else{
                //if different element found, then place just after ith element and then i++ and j++
                nums[i+1] = nums[j];
                i++;
                j++;
            }
         }
        return i+1;
    }
};