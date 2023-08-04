class Solution {
public:
    bool found(int i, string s, set<string>& st, vector<int>& memo) {
        if (i == s.size())
            return true;
        
        if (memo[i] != -1) {
            return memo[i];
        }
        
        string str = "";
        for (int j = i; j < s.size(); j++) {
            str += s[j];
            if (st.find(str) != st.end()) {
                if (found(j + 1, s, st, memo)) {
                    memo[i] = true;
                    return true;
                }
            }
        }
        
        memo[i] = false;
        return false;
    }
    bool wordBreak(string s, vector<string>& dict) {
        set<string>st;
        int n = s.size();
        vector<int>dp(n,-1);
        for(auto x:dict)
            st.insert(x);
        return found(0,s,st,dp);
    }
};