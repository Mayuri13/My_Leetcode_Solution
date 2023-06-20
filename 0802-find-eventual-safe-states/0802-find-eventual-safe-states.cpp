class Solution {
public:
    bool dfs(int src, vector<int>&pathVis, vector<int>&vis,vector<vector<int>>& graph, vector<int>&check){
        vis[src]=1;
        pathVis[src]=1;
        
        for(auto it:graph[src]){
            if(pathVis[it]==1){
                return false;
            }
            else if(!vis[it]){
                if(dfs(it,pathVis,vis,graph,check)==false)
                    return false;
            }
        }
        check[src]=1;
        pathVis[src]=0;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>safeNodes;
        vector<int>vis(n,0), check(n,0), pathVis(n,0);
        
        for(int i=0; i<graph.size(); i++){
            if(!vis[i]){
                dfs(i,pathVis,vis,graph,check);
            }
        }
        for(int i=0; i<n; i++){
            if(check[i])
                safeNodes.push_back(i);
        }
        return safeNodes;
    }
};