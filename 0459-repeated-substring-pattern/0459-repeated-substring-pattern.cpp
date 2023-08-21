class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string tmp = s;
        for(int i=0; i<s.size()-1; i++){
            char ch = s[0];
            s.erase(0,1);
            s.push_back(ch);
            if(tmp==s)
                return true;
        }
        return false;
    }
};