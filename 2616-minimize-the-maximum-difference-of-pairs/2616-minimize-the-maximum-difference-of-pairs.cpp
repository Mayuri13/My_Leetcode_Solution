class Solution {
public:
    bool find(vector<int>&nums, int diff, int p){
        for(int i=1; i<nums.size(); i++){
            if(nums[i]-nums[i-1]<=diff){
                p--;
                i++;
            }
        }
        return p<=0;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size(), ans=0;
        sort(nums.begin(),nums.end());
        int s = 0, e = nums[n-1]-nums[0];
        while(s<=e){
            int mid = e - (e-s)/2;
            if(find(nums,mid,p)){
                ans = mid;
                e = mid-1;
            }
            else
                s = mid+1;
        }
        return ans;
    }
};