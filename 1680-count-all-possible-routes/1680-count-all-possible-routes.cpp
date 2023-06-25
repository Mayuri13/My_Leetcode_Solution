class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {                
        const int MOD = 1000000007;
        int n = locations.size();    
        
        vector<vector<int>> dp(n, vector<int>(fuel + 1, 0));
        for (int f = 0; f <= fuel; f++) {
            dp[finish][f] = 1;
        }
        
        // for each fuel, we calculate all cross between cities
        for (int f = 0; f <= fuel; f++) {
            for (int city = 0; city < n; city++) {            
                for (int nextCity = 0; nextCity < n; nextCity++) {               
                    if (nextCity != city && f >= abs(locations[nextCity] - locations[city])) {
                        dp[city][f] = (dp[city][f] + dp[nextCity][f - abs(locations[nextCity] - locations[city])]) % MOD;
                    }
                }
            }            
        }
        return dp[start][fuel];
    }
};


//Attempted myself
// class Solution {
// public:
//     int mod = 1e9+7;
//     int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
//         int n=locations.size(), ans=0;
//         vector<vector<int>>adj(n);
//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){
//                 if(i==j) continue;
//                 adj[i].push_back(j);
//             }
//         }
//         queue<pair<int,int>>q;
//         q.push({start,fuel});
//         while(!q.empty()){
//             int node = q.front().first;
//             int fuelRem = q.front().second;
//             q.pop();
//             if(node==finish){
//                 ans++;
//             }
//             for(auto it:adj[node]){
//                 int f = fuelRem - abs(locations[node]-locations[it]);
//                 if(f>=0){
//                     q.push({it,f});
//                 }
//             }
//         }
//         return ans%mod;
//     }
// };