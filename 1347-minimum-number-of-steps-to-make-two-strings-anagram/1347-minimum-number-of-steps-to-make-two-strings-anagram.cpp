class Solution {
public:
    int minSteps(string s, string t) {
        int ans = 0;
        map<char,int>mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }
        for(int i=0; i<t.size(); i++){
            if(mp.find(t[i])!=mp.end()){
                if(mp[t[i]]<=0)
                    ans++;
                else
                    mp[t[i]]--;
            }
            else
                ans++;
        }
        return ans;
    }
};