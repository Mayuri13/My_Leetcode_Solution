class Solution {
public:
    int partitionString(string s) {
        set<char>st;
        int ans1=0;
        for(int i=0; i<s.size(); i++){
            if(st.find(s[i])!=st.end()){
                st.clear();
                ans1++;
            }
            
            st.insert(s[i]);
            
        }
        ans1 +=1 ;
        return ans1;
    }
};