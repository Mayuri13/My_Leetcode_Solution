class Solution {
public:
    //More Optimized solution
    vector<int> adj[2005];
    int dp[2005];
    int help(int i,int n){
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=1e9;
        for(auto x:adj[i]){
            int tmp=1+help(x+1,n);
            ans=min(ans,tmp);
        }
        return dp[i]=ans;
    }
    int minCut(string s) {
        int n=s.size();
        int check[n][n];      //to store palindromic status of each substring
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0){
                    check[i][j]=1;
                }
                else if(g==1){
                    check[i][j]=(s[i]==s[j]);
                }
                else{
                    check[i][j]=(check[i+1][j-1]==1 ? (s[i]==s[j] ? 1 : 0) : 0);
                }
            }
        }
        
        //storing all indexes j in adj[i] such that s[i]...s[j] is palindrome
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check[i][j]){
                    adj[i].push_back(j);
                }
            }
        }

        memset(dp,-1,sizeof(dp));
        return help(0,n)-1;       
    }  
    
    //Tabulation Solution
    // bool isPalindrome(string str){
    //     if(str.size()==1)
    //         return true;
    //     int i=0, j = str.size()-1;
    //     while(i<=j){
    //         if(str[i++]!=str[j--])
    //             return false;
    //     }
    //     return true;
    // }
    // int minCut(string s) {
    //     int n = s.size();
    //     vector<int>dp(n+1,0);
    //     for(int i=n-1; i>=0; i--){
    //         int mini = 1e9;
    //         string temp = "";
    //         for(int j=i; j<n; j++){
    //             temp += s[j];
    //             if(isPalindrome(temp)){
    //                 int cost = 1 + dp[j+1];
    //                 mini = min(mini,cost);
    //             }
    //         }
    //         dp[i] = mini;
    //     }
    //     return dp[0]-1;
    // }
    
    //Memoization Solution
//     bool isPalindrome(string str, int i, int j){
//         if(str.size()==1)
//             return true;
//         while(i<=j){
//             if(str[i++]!=str[j--])
//                 return false;
//         }
//         return true;
//     }
//     int find(int i, int k, string s, vector<int>&dp){
//         if(i==s.size() || isPalindrome(s, i, k))
//             return 0;
//         if(dp[i]!=-1)
//             return dp[i];
//         int mini = 1e9;
        
//         for(int j=i; j<k; j++){
    
//             if(isPalindrome(s, i, j)){
//                 int cost = 1 + find(j+1,k,s,dp);
//                 mini = min(mini,cost);
//             }
//         }
//         dp[i] = mini;
//         return dp[i];
//     }
//     int minCut(string s) {
//         //As the recursive function does a partition at the end of the string when i==n-1, so -1 is neede in           the answer
//         int n = s.size();
//         vector<int>dp(n,-1);
//         return find(0,n-1,s,dp);
//     }
};