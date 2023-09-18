class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        set<int>s;
        vector<int>ans;
        for(int i=0; i<=m; i++){
            for(int j=0; j<n && ans.size()<k; j++){
                if(i == m || mat[j][i] == 0){
                    if(s.find(j)==s.end()){
                        ans.push_back(j);
                        s.insert(j);
                    }
                }
            }
            if(ans.size() == k) 
                break;
        }
        return ans;
    }
};