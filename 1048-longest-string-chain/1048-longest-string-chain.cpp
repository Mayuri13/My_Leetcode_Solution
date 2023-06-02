class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n= words.size(), mx=1;
        sort(words.begin(), words.end(),[](string &a, string &b){
            return a.size()<b.size();
        });
        
        vector<int>dp(n,1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                //Checking predecessor or not
                int l = 0, k = 0, cnt=0;
                while(l<words[j].size() && k<words[i].size()){
                    if(words[j][l]==words[i][k]){
                        l++;
                        k++;
                    }
                    else if(cnt==0 && (words[j][l]!=words[i][k])){
                        //case of inserting
                        k++;
                        cnt++;
                    }
                    else
                        break;
                        
                }
                if(cnt==1 && (l==words[j].size()) && (k==words[i].size()) && (dp[i]<1+dp[j]))
                    dp[i] = 1+dp[j];
                if(cnt==0 && (words[i].size() - k)==1 && (dp[i]<1+dp[j]))
                    dp[i] = 1+dp[j];
                if(l<words[j].size())
                    continue;
                
            }
            mx = max(mx,dp[i]);
        }
        return mx;
    }
};