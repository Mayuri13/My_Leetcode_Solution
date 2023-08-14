class Solution {
public:
    int partitionString(string s) {
        set<char>st;
        int ans1=0, ans2 = 0;
        for(int i=0; i<s.size(); i++){
            if(st.find(s[i])!=st.end()){
                st.clear();
                ans1++;
            }
            
            st.insert(s[i]);
            
        }
        ans1 +=1 ;
        for(int i=s.size()-1; i>=0; i--){
            if(st.find(s[i])!=st.end()){
                st.clear();
                ans2++;
            }
            
            st.insert(s[i]);
            
        }
        ans2 +=1 ;
        return min(ans1,ans2);
    }
};