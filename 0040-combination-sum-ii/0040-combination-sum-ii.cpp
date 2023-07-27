class Solution {
public:
    void find(int i, int tar, vector<int>&c, vector<vector<int>>&ans, vector<int>&v){
        if(tar==0){
            ans.push_back(v);
            return;
        }
        for(int j=i; j<c.size(); j++){
            if(j>i && c[j]==c[j-1]) continue;
            if(tar<c[j]) break;
            v.push_back(c[j]);
            find(j+1,tar-c[j],c,ans,v);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int tar) {
        vector<vector<int>>ans;
        vector<int>v;
        sort(c.begin(),c.end());
        find(0,tar,c,ans,v);
        return ans;
    }
};