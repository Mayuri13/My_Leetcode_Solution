class Solution {
public:
    bool hasCycle(vector<vector<int>>& adj, int src, vector<int>&vis, vector<int>&pathVis){
        vis[src] = 1;
        pathVis[src] = 1;
        for(auto it:adj[src]){
            if(pathVis[it] == 1) return true;
            else if(vis[it] == 0){
                if(hasCycle(adj, it, vis, pathVis))
                    return true;
            }
        }
        pathVis[src] = 0;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& courses) {
        vector<vector<int>> adj(n);
        for(int i = 0; i<courses.size(); i++){
            adj[courses[i][1]].push_back(courses[i][0]);
        }
        vector<int>vis(n,0);
        vector<int>pathVis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(hasCycle(adj,i,vis,pathVis))
                    return false;
            }
        }
        return true;
    }
};