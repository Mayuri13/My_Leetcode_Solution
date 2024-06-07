class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m =maze[0].size();
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        int dx[4] = {-1,0,0,1};
        int dy[4] = {0,-1,1,0};

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>>q;

        q.push({0, {entrance[0], entrance[1]}});
        dist[entrance[0]][entrance[1]] = 0;

        while(!q.empty()){
            int dis = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            
            q.pop();

            if(row == 0 || row == n-1 || col == 0 || col == m-1){
                if(row != entrance[0] || col != entrance[1])
                    return dis;
            } 

            for(int k = 0; k<4; k++){
                int nr = row + dx[k];
                int nc = col + dy[k];

                if(nr >= 0 && nr < n && nc >=0 && nc < m && maze[nr][nc] == '.' && (1 + dis) < dist[nr][nc]){
                    dist[nr][nc] = 1 + dis;
                    q.push({dist[nr][nc], {nr,nc}});
                }
            }
        }
        return -1;
    }
};