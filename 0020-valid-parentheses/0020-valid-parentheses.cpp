class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        st.push(s[0]);
        for(int i=1; i<s.size(); i++){
            if(s[i]==')' && !st.empty() && st.top()=='(')
                st.pop();
            else if(s[i]=='}' && !st.empty() && st.top()=='{')
                st.pop();
            else if(s[i]==']' && !st.empty() && st.top()=='[')
                st.pop();
            else 
                st.push(s[i]);
        }
        if(st.empty()==true)
            return true;
        return false;
    }
};