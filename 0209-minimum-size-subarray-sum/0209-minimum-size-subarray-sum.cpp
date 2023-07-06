class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0,ans=INT_MAX,j=0,cnt=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            while(sum>=target){
                    ans=min(ans,i-j+1);
                    sum-=nums[j++];
                }
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};