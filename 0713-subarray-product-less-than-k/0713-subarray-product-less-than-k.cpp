class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0, l=0, temp = 1;;
        for(int r=0; r<nums.size(); r++){
            temp *= nums[r];
            while(l<=r && temp>=k){
                temp /= nums[l++];
            }
            ans += (r-l+1);
        }
        return ans;
    }
};