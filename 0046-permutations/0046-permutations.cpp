class Solution {
public:
    void FindPerm(int idx, vector<vector<int>>& ans, vector<int>& ds, vector<int>& nums){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        if(idx>=nums.size()) return;
        for(int i=idx; i<nums.size(); i++){
            swap(nums[i],nums[idx]);
            ds.push_back(nums[idx]);
            FindPerm(idx+1,ans,ds,nums);
            swap(nums[idx],nums[i]);
            ds.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        FindPerm(0,ans,ds,nums);
        return ans;
    }
};