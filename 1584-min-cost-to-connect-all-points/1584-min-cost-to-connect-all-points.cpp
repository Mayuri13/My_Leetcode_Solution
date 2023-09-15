class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,vector<int>>, vector<pair<int,vector<int>>>, greater<pair<int,vector<int>>>> pq;
        int n = points.size();
        vector<int>vis(n,0);
        vector<int>tmp = {points[0][0],points[0][1],0};
        
        pq.push({0,tmp});
        int sum = 0;
        
        //Implementing prim's algorithm to find minimum spanning tree
        while(!pq.empty()){
            int nodex = pq.top().second[0], nodey = pq.top().second[1]; 
            int idx = pq.top().second[2], wt = pq.top().first;
            pq.pop();
            
            if(vis[idx]) continue;
            vis[idx] = 1;
            sum += wt;
            for(int i=0; i<n; i++){
                if(i == idx) continue;
                if(vis[i] == 0){
                    wt = abs(nodex - points[i][0]) + abs(nodey - points[i][1]);
                    vector<int>tmp1 = {points[i][0],points[i][1],i};
                    pq.push({wt,tmp1});
                }
            }
        }
        return sum;
    }
};