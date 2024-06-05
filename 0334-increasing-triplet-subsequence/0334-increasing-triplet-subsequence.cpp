class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int>tmp;
        tmp.push_back(nums[0]);
        int len = 1;

        for(int i=1; i<nums.size(); i++){
            if(tmp.back() >= nums[i]){
                int idx = lower_bound(tmp.begin(), tmp.end(), nums[i]) - tmp.begin();
                tmp[idx] = nums[i];
            }
            else{
                tmp.push_back(nums[i]);
                len++;
            }
        }
        return len >= 3;
    }
};