class Solution {
public:
    bool rotateString(string s, string goal) {
        // If the lengths are different, return false
        if (s.size() != goal.size()) {
            return false;
        }

        //Concatinating  
        string concat = goal + goal;
        
        if(concat.find(s) != string::npos)
            return true;

        return false;
    }
};