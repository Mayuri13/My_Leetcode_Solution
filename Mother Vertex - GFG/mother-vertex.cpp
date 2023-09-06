//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
	void dfs(int s, vector<int>adj[], vector<bool>&visited )
    {
        visited[s]= true;
        for(auto helper:adj[s])
        {
            if(!visited[helper]) dfs(helper,adj,visited);
        }
    }
    
    
    int findMotherVertex(int V, vector<int>adj[])
    {
        vector<bool>visited(V,false);
        int ans;
        for(int i=0; i<V; i++)
        {
            if(!visited[i]){
                dfs(i, adj,visited);
                ans=i;
            }
        }
        
        fill(visited.begin(), visited.end(),false);
        dfs(ans, adj,visited);
        for(int i=0; i<V; i++)
        {
            if(!visited[i]) return -1;
        }
        
        return ans;
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends