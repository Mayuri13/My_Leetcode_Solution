class Solution {
public:
    bool bfs(int node, vector<vector<int>>& graph, vector<int>&vis){
        bool flag = true;
        queue<pair<int,bool>>q;
        q.push({node,flag});
        vis[node] = flag;
        while(!q.empty()){
            int src = q.front().first;
            bool color = q.front().second;       
            q.pop();
            for(auto it:graph[src]){
                if(vis[it]==-1){
                    q.push({it,!color});
                    vis[it] = !color; 
                }
                else if(vis[it]==color){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,-1);
        for(int i=0; i<n; i++){
            if(vis[i]==-1){
                if(bfs(i,graph,vis)==false)
                    return false;
            }
        }
        return true;
    }
};