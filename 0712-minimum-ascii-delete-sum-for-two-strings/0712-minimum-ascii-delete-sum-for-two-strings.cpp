class Solution {
public:
    //Space Optimised Approach (DP Tabulation using 1d vector)
    
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size(), val=0;
        vector<int>prev(m+1,0), curr(m+1,0);
        for(int j=1; j<=m; j++){
            val += s2[j-1];
            prev[j] = val;
        }
        val = 0;
        for(int i=1; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(j==0){
                    val += s1[i-1];
                    curr[j] = val;
                    continue;
                }
                if(s1[i-1]==s2[j-1])
                    curr[j] = prev[j-1];
                else
                    curr[j] = min((s1[i-1] +prev[j]),(s2[j-1] + curr[j-1]));
            }
            prev = curr;
        }
        return prev[m];
    }
};