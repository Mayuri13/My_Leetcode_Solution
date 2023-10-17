class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, l = 0, n = s.size();
        set<char>st;
        for(int i=0; i<n; i++){
            if(st.find(s[i])!=st.end()){
                ans = max(ans,i-l);
                while(l<i){
                    st.erase(s[l]);
                    if(s[l++] == s[i])
                        break;
                }
                st.insert(s[i]);
            }
            else{
                st.insert(s[i]);
            }
        }
        ans = max(ans,n-l);
        return ans;
    }
};