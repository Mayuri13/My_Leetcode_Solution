class Solution {
public:
    int DX[4] = {-1, 1, 0, 0};
    int DY[4] = {0, 0, -1, 1};
    int minimumEffortPath(vector<vector<int>>& h) {
        priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,           int>>>> pq;
        int n = h.size(), m = h[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int maxDiff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if(r==n-1 && c==m-1)
                return maxDiff;
            for(int i = 0; i < 4; i++){
            int cx = r + DX[i];
            int cy = c + DY[i];
            if (cx >= 0 && cx < n && cy >= 0 && cy < m) {
                int newEffort = max(maxDiff,abs(h[r][c]-h[cx][cy]));
                if(newEffort<dist[cx][cy]){
                    dist[cx][cy]=newEffort;
                    pq.push({newEffort,{cx,cy}});
                } 
            }
            }
        }
        return 0;
    }
};