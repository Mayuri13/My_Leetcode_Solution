class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<pair<char, int>>st;
        string ans = "";

        for(int i=0; i<s.size(); i++){
            if(s[i] == ')'){
            //Primitive parenthesis is presesnt when st.size() == 1, bcz no more parenthesis before it (it is the outermost)
                if(st.size() == 1){
                    int idx = st.top().second;
                    ans += s.substr(idx+1, i-idx-1);
                }
                st.pop();
            }
            else{
                st.push({'(',i});
            }
        }
        return ans;
    }
};