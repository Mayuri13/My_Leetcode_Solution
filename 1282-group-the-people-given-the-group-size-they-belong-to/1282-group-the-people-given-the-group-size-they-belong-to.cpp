class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        map<int,vector<int>>m1;
        for(int i=0; i<groupSizes.size(); i++){
            // int j = groupSizes[i];
            if(m1[groupSizes[i]].size()!=groupSizes[i]){
                m1[groupSizes[i]].push_back(i);
            }
            else{
                ans.push_back(m1[groupSizes[i]]);
                m1[groupSizes[i]].clear();
                m1[groupSizes[i]].push_back(i);
            }
        }
        for(auto x:m1){
            ans.push_back(x.second);
            
        }
        return ans;
    }
};