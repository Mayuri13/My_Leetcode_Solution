class Solution {
public:
    //Using detecting a cycle alsorithm
    bool dfs(int src, vector<int>&vis, vector<int>&pathVis, vector<vector<int>>& adj){
        vis[src]=1;
        pathVis[src] = 1;
        for(auto it:adj[src]){
            if(pathVis[it]==1)
                return false;
            else if(!vis[it]){
                if(dfs(it,vis,pathVis,adj)==false)
                    return false;
            }
        }
        pathVis[src]=0;
        return true;
    }
    
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int>vis(n,0), pathVis(n,0);
        vector<vector<int>>adj(n);
        for(int i=0; i<p.size(); i++){
            adj[p[i][1]].push_back(p[i][0]);
        }
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,adj)==false)
                    return false;
            }
        }
        
        return true;
    }
};