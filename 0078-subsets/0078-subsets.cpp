class Solution {
public:
    void solve(int idx, int n, vector<int>&nums, vector<vector<int>>&ans, vector<int>&ds){
        if(idx == n){
            ans.push_back(ds);
            return;
        }
        
        //Picking the element
        ds.push_back(nums[idx]);
        solve(idx+1,n,nums,ans,ds);

        //Not picking teh element
        ds.pop_back();
        solve(idx+1,n,nums,ans,ds);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        int n = nums.size();
        solve(0,n,nums,ans,ds);
        return ans;
    }
};