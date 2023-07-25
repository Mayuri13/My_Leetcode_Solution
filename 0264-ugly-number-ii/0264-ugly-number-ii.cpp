class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n);
        dp[0] = 1;
        int p1 = 0, p2 = 0, p3 = 0;
        for(int i=1; i<n; i++){
            int two = 2*dp[p1];
            int thr = 3*dp[p2];
            int fiv = 5*dp[p3];
             dp[i] = min(two, min(thr,fiv));
            if(dp[i]==two) p1++;
            if(dp[i]==thr) p2++;
            if(dp[i]==fiv) p3++;
        }
        return dp[n-1];
    }
};