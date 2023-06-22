//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(int src, stack<int>&st, vector<vector<pair<int,int>>>&adj, vector<int>&vis){
        vis[src] = 1;
        for(auto it:adj[src]){
            if(!vis[it.first])
               dfs(it.first,st,adj,vis); 
        }
        st.push(src);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // step1:
        // performing topological sort using dfs and storing in stack
        vector<vector<pair<int,int>>>adj(N);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        stack<int>st;
        vector<int>vis(N,0); 
        for(int i=0; i<N; i++){
            if(!vis[i]){
                dfs(i,st,adj,vis);
            }
        }
        
        //step2:
        //one one pop all elements out of stack and mark their distance in the dis 
        vector<int>dis(N,INT_MAX);
        dis[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(dis[node]==INT_MAX){
                continue;
            }
            int x = dis[node];
            for(auto it:adj[node]){
                dis[it.first] = min(dis[it.first],x+it.second);
            }
        }
        for(int i=0; i<N; i++){
            if(dis[i]==INT_MAX)
                dis[i]=-1;
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends