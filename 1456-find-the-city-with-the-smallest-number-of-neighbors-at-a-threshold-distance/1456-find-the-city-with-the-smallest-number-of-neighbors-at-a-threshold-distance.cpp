class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>>adjM(n,vector<int>(n,1e9));
        for(int i=0; i<edges.size(); i++){
            adjM[edges[i][0]][edges[i][1]] = edges[i][2];
            adjM[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for(int i=0; i<n; i++){
            adjM[i][i] = 0;
        }
        for(int via = 0; via<n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    adjM[i][j] = min(adjM[i][j], adjM[i][via] + adjM[via][j]);
                }
            }
        }
        int mxCnt = 1e9, k = -1;
        for(int i=0; i<n; i++){
            int  cnt = 0;
            for(int j=0; j<n; j++){
                if(adjM[i][j]!=0 && adjM[i][j] <= dt){
                    cnt++;
                }  
            }
            if(mxCnt >= cnt){
                mxCnt = cnt;
                k=i;
            }
        }
        return k;
    }
};