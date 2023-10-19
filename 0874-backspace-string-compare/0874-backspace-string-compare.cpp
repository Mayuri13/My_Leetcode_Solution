class Solution {
public:
    string find(string s){
        stack<char>st;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '#'){
                if(!st.empty())
                    st.pop();
                else
                    continue;
            }
            else{
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty()){
            char ch = st.top();
            st.pop();
            ans += ch;
        }
        return ans;
    }
    bool backspaceCompare(string s, string t) {
        return find(s) == find(t);
    }
};