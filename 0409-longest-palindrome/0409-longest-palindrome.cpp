class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }

        int ans = 0;
        bool flag = false;

        for(auto it:mp){
            if(it.second % 2 != 0){
                ans += it.second-1;
                flag = true;
            }
            else
                ans += it.second;
            
        }
        if(flag)
            ans++;
        return ans;
    }
};