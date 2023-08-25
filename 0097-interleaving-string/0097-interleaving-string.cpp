class Solution {
public:
//     bool find(int i, int j, int k, string s1, string s2, string s3){
//         // if(k==s3.size()){
//         //     return true;
//         // }
//         // if(i==s1.size() && k<) return true;
//         if(i == s1.size() && k < s3.size()) return s2.substr(j)==s3.substr(k);
//         if(j == s2.size() && k < s3.size()) return s1.substr(i)==s3.substr(k);
        
//         if(s1[i]==s3[k] && s2[j]!=s3[k])
//             return find(i+1,j,k+1,s1,s2,s3);
//         else if(s1[i]!=s3[k] && s2[j]==s3[k])
//             return find(i,j+1,k+1,s1,s2,s3);
//         else if(s1[i]==s3[k] && s2[j]==s3[k])
//             return find(i+1,j,k+1,s1,s2,s3) || find(i,j+1,k+1,s1,s2,s3);
//         return false;
//     }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if(n1==0)
            return s2==s3;
        if(n2==0)
            return s1==s3;
        if((n1 + n2) != n3) return false;
        vector<vector<vector<int>>>dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,0)));
        for(int j=n2-1; j>=0; j--){
            for(int k=n3-1; k>=0; k--){
                dp[n1][j][k] = s2.substr(j)==s3.substr(k);
            }
        }
        for(int i=n1-1; i>=0; i--){
            for(int k=n3-1; k>=0; k--){
                dp[i][n2][k] = s1.substr(i)==s3.substr(k);
            }
        }
        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                for(int k=n3-1; k>=0; k--){
                    if(s1[i]==s3[k] && s2[j]!=s3[k])
                        dp[i][j][k] = dp[i+1][j][k+1];
                    else if(s1[i]!=s3[k] && s2[j]==s3[k])
                        dp[i][j][k] = dp[i][j+1][k+1];
                    else if(s1[i]==s3[k] && s2[j]==s3[k])
                        dp[i][j][k] = dp[i+1][j][k+1] || dp[i][j+1][k+1];
                }
            }
        }
        return dp[0][0][0];
    }
};