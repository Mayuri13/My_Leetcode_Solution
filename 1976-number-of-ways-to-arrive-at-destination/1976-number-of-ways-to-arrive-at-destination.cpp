class Solution {
public:
    int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>>adj[n];
        
        for(auto it: roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>pq;
    
        vector<long long> dist(n,LONG_MAX),ways(n,0);
        dist[0]=0;
        ways[0]=1;
        int mod=(1e9 +7);
        pq.push({0,0});
        while(!pq.empty())
        {
          long long d=pq.top().first;
          long long int node=pq.top().second;
          pq.pop();
          for(auto it:adj[node])
          {
              long long adjnode=it.first;
              long long int edgwt=it.second;
      //this is the first time i have entered with short distance 
              if((d+edgwt)<dist[adjnode])
              {
                  dist[adjnode]=d+edgwt;
                  ways[adjnode]=ways[node];
                  pq.push({dist[adjnode],adjnode});
              } else if((d+edgwt)==dist[adjnode])
              {
                   ways[adjnode]=((ways[adjnode]%mod + ways[node])%mod)%mod;
              }
          }
         
        }
        return ways[n-1]%mod;
    }
};