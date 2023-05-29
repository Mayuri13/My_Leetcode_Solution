class Solution {
public:
    long long minimumCost(string s) {
        int n = s.size();
        if(n==1)
            return 0;
        int i=1;
        long long ans=0;
        while(i<n){
            if(i<=n/2){
                if(s[i-1]!=s[i]){
                    ans+=i;
                }
            }
            else{
                if(s[i-1]!=s[i]){
                    ans+= n-i;
                }
            }
            i++;
        }
        return ans;
    }
};