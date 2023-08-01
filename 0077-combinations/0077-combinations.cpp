class Solution {
public:
    void find(int i, int n, int k, vector<vector<int>>&ans, vector<int>&v){
        if(i==n+1){
            if(v.size()==k)
                ans.push_back(v);
            return;
        }
        if(v.size()==k){
            ans.push_back(v);
            return;
        }
        v.push_back(i);
        find(i+1,n,k,ans,v);
        v.pop_back();
        find(i+1,n,k,ans,v);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>v;
        find(1,n,k,ans,v);
        return ans;
    }
};