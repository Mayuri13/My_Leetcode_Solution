class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int>inDegree(n,0), ans;
        vector<vector<int>>adj(n);
        for(int i=0; i<p.size(); i++){
            adj[p[i][1]].push_back(p[i][0]);
        }
	    for(int i=0; i<p.size(); i++){
	        inDegree[p[i][0]]++;
	    }
	    queue<int>q;
	    for(int i=0; i<n; i++){
	        if(inDegree[i]==0){
	            q.push(i);
	        }
	    }
	    while(!q.empty()){
	        int node = q.front();
	        ans.push_back(node);
	        q.pop();
	        for(auto it:adj[node]){
	            inDegree[it]--;
	            if(inDegree[it]==0)
	                q.push(it);
	        }
	    }
        if(ans.size()<n)
            return {};
	    return ans;
    }
};