class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())
            return false;
        if(s==goal){
            set<int>sh;
            for(int i=0; i<s.size(); i++){
                if(sh.find(s[i])!=sh.end())
                    return true;
                else{
                    sh.insert(s[i]);
                }
            }
        }
        else{
            vector<int>diff(2,0);
            int cnt=0;
            for(int i=0; i<s.size(); i++){
                if(s[i]!=goal[i]){
                    if(++cnt > 2) return false;
                    diff[cnt-1] = i;
                }
            }
            if(cnt==1)
                return false;
            if(s[diff[0]]==goal[diff[1]] && s[diff[1]]==goal[diff[0]])
                return true;
        }
        return false;
    }
};