class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>pref(n), suff(n), ans(n);
        pref[0] = nums[0], suff[n-1] = nums[n-1];
        int p = nums[0], s = nums[n-1];
        
        for(int i=1; i<n-1; i++){
            p *= nums[i];
            s *= nums[n-i-1];
            pref[i] = p;
            suff[n-i-1] = s;
        }
        for(int i=0; i<n; i++){
            if(i==0){
                ans[i] = suff[i+1];
                continue;
            }
            if(i == n-1){
                ans[i] = pref[i-1];
                continue;
            }
            ans[i] = pref[i-1]*suff[i+1];
        }
        return ans;
    }
};