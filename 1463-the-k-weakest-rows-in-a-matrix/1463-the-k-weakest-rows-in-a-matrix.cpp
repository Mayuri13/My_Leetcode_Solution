class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i=0; i<mat.size(); i++){
            int curr = 0;
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j] == 1) curr++;
            }
            // if(prev <= curr)
            //     pq.push({prev,i-1});
            // if(i == (mat.size()-1)) 
            pq.push({curr,i});
        }
        vector<int>ans;
        while(!pq.empty() && k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};