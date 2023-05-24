class Solution {
public:
    string shortestCommonSupersequence(string t1, string t2) {
        if(t1==t2)
            return t1;
        int n = t1.size(), m = t2.size();
        string ans="";
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0; i<=m; i++){
            dp[0][i]=0;
        }
        for(int i=0; i<=n; i++){
            dp[i][0]=0;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(t1[i-1]==t2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        //for getting the LCS we must traverse from i=n and j=m
        int i = n, j=m;
        while (i>0 && j>0)
        {
            if(t1[i-1]==t2[j-1]){
                ans+=t1[i-1];
                i=i-1;
                j=j-1;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                    ans+=t1[i-1];
                    i = i-1;
            }
            else{
                ans+=t2[j-1];
                j=j-1;
            }
        }
        // cout<<ans<<" ";
        while(i>0){
            ans+=t1[i-1];
            i--;
        }
        while(j>0){
            ans+=t2[j-1];
            j--;
        }
        // int l = ans.size(), k=0;
        //Reversing the string
        reverse(ans.begin(), ans.end());
        return ans;
    }
};