class Solution {
public:
    bool dfs(int src, bool col, vector<int>& color, vector<vector<int>>& graph){
        color[src] = col;
        for(auto it:graph[src]){
            if(color[it] == -1){
                if(dfs(it, !col, color, graph) == false)
                    return false;
            }
            else{
                if(color[it] == col)
                    return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);   //for determining graph is bipartite or not, use color seperation
        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(dfs(i, false, color, graph) == false)
                    return false;
            }
        }
        return true;
    }
};