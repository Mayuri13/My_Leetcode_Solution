class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& e, vector<double>& s, int start, int end) {
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0; i<e.size(); i++){
            adj[e[i][0]].push_back({e[i][1],s[i]});
            adj[e[i][1]].push_back({e[i][0],s[i]});
        }
        vector<double>prob(n,-1);
        priority_queue<pair<double,int>>pq;
        pq.push({1,start});
        prob[start] = 0;
        while(!pq.empty()){
            double wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(node==end) continue;
            for(auto it:adj[node]){
                int adjN = it.first;
                double edjWt = it.second;
                if(prob[adjN]< wt*edjWt){
                    prob[adjN] = wt*edjWt;
                    pq.push({prob[adjN],adjN});
                }
            }
        }
        if(prob[end]==-1)
            return 0;
        return prob[end];
    }
};