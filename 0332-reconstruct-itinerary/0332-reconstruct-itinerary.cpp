class Solution {
public:
    void dfs(string dep, map<string, vector<string>>& graph, vector<string>& ans){
        vector<string> &tmp = graph[dep];
        while(!tmp.empty()){
            string val = graph[dep].back();
            graph[dep].pop_back();
            dfs(val, graph, ans);
        }
        ans.push_back(dep);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, vector<string>>graph;
        vector<string>ans;
        
        for(int i=0; i<tickets.size(); i++){
            graph[tickets[i][0]].push_back(tickets[i][1]);
        }
        
        //sort the destinations lexicographically (in reverse order)
        for(auto &it : graph){
            sort(it.second.rbegin(), it.second.rend());
        }
        
        //Start dfs from JFK
        dfs("JFK",graph,ans);
        reverse(ans.begin() , ans.end());
        return ans;
    }
};