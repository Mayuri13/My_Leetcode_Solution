class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;

        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == target) return true;

            // extra condition -> can't check for left/right sorted
            if(nums[lo] == nums[mid] && nums[mid] == nums[hi]){
                lo++; hi--;
            }
            // rest is same as rotated sorted array I

            // left sorted
            else if(nums[lo] <= nums[mid]) {
                // element present in the left side
                if(nums[lo] <= target && nums[mid] > target) hi = mid-1;
                // element not present in left side
                else lo = mid+1;
            }

            // right sorted
            else {
                // element present in the right side
                if(nums[mid] < target && target <= nums[hi]) lo = mid+1;
                // element not present in right side
                else hi = mid-1;
            }
        }

        return false;
    }
};