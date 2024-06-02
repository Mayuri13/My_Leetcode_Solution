class Solution {
public:
    void find(int n, int open, int close, string tmp, vector<string>&ans){
        if(tmp.size() == 2*n){
            ans.push_back(tmp);
            return;
        }

        if(open < n){
            tmp += '(';
            find(n, open+1, close, tmp, ans);
            tmp.pop_back();
        }

        if(close < open){
            tmp += ')';
            find(n, open, close+1, tmp, ans);
            tmp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;

        find(n, 0, 0, "", ans);
        return ans;
    }
};