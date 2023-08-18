class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>>adj(n);
        for(int i=0; i<roads.size(); i++){
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                bool flag = false;
                for(int k=0; k<adj[i].size(); k++){
                    if(adj[i][k]==j) flag = true;
                }
                int rank = adj[i].size() + adj[j].size();
                if(flag)
                    ans = max(ans,rank-1);
                
                else
                    ans = max(ans,rank);
            }
        }
        return ans;
    }
};