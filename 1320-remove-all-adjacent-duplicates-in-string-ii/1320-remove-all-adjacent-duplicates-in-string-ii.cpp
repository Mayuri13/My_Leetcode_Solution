class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>>st;

        for(int i=0; i<s.size(); i++){
            if(!st.empty() && st.top().first == s[i]){
                int cnt = st.top().second;
                cnt++;
                st.pop();

                if(cnt != k)
                   st.push({s[i],cnt});
            }
            else{
                st.push({s[i], 1});
            }
        }
        string ans = "";
        while(! st.empty()){
            ans.append(st.top().second, st.top().first);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};