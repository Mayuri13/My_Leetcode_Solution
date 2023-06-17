class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>&vis){
        vis[node]=1;
        for(int j=0; j<adj[node].size(); j++){
            if(adj[node][j]==1 && vis[j]!=1){
                dfs(j,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<int>vis(v,0);
        int cnt=0;
        for(int i=0; i<adj.size(); i++){
            if(vis[i]==0){
                dfs(i,adj,vis);
                cnt++;
            }
        }
        
        return cnt;
    }
};