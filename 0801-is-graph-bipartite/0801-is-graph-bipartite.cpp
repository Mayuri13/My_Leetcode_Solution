class Solution {
public:
    bool bfs(int src, vector<int>& color, vector<vector<int>>& graph){
        queue<pair<int,bool>>q;
        q.push({src, false});
        color[src] = 0;
        while(!q.empty()){
            int node = q.front().first;
            bool col = q.front().second;
            q.pop();
            for(auto it:graph[node]){
                if(color[it]!=-1){
                    if(color[it] == col)
                        return false;
                }
                else{
                    q.push({it, !col});
                    color[it] = !col;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);   //for determining graph is bipartite or not, use color seperation
        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(bfs(i, color, graph) == false)
                    return false;
            }
        }
        return true;
    }
};