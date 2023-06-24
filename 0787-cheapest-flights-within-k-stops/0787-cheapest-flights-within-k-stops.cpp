class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        vector<int>dist(n,INT_MAX);
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,                           greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{src,0}});
        dist[src]=0;
        while(!pq.empty()){
            int stop = pq.top().first;
            int node = pq.top().second.first;
            int dis = pq.top().second.second;
            pq.pop();
            if(stop>k){
                continue;
            }
            for(auto it:adj[node]){
                int adjNode = it.first;
                int edjW = it.second;
                if(dist[adjNode]>dis+edjW){
                    dist[adjNode]=dis+edjW;
                    pq.push({stop+1,{it.first,dist[adjNode]}});
                }
            }
        }
        if(dist[dst]!=INT_MAX)
            return dist[dst];
        return -1;
    }
};