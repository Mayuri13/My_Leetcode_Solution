class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //step1 (Traverse from back and find the first nums[i]<nums[i+1] and mark ind1 as i)
        int n = nums.size(), ind1 = -1, ind2 = -1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                ind1 = i;
                break;
            }
        }
        
        if(ind1 == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        //step2 (Traverse from back again anad find the next larger element than nums[ind1])
        for(int i=n-1; i>=0; i--){
            if(nums[ind1] < nums[i]){
                ind2 = i;
                break;
            }
        }
        
        //step3 (swap nums[ind1] and nums[ind2])
        swap(nums[ind1],nums[ind2]);
        
        //step4 (reverse all the elements from ind1+1 to end)
        reverse(nums.begin()+ind1+1, nums.end());
        return;
    }
};