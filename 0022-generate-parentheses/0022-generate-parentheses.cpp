class Solution {
public:
    void find(int n, int open, int close, string tmp, vector<string>&ans){
        //If tmp is of 2n size 
        if(tmp.size() == 2*n){
            ans.push_back(tmp);
            return;
        }

        //First inserting the open bracket
        if(open < n){
            tmp += '(';
            find(n, open+1, close, tmp, ans);
            tmp.pop_back();
        }

        //Inserting the closing brackets only when open > close, means opens are inserted first & then closing
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