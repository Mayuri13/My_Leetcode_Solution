class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==1){
            return strs[0];
        }
        string s=strs[0];  //storing the first word of strs in s 
        string s1="";      //store the final common prefix

        for(int i=1; i<n; i++){
            //Traversing through the vector strs
            s1="";

            for(int j=0; j<strs[i].size(); j++){
                //comparing thorugh each character of strs[i]
                if(s[j]==strs[i][j])
                    s1+=s[j];
                else
                    break;
            }
            if(s1=="")
                break;
            else
                s=s1;   //placing the common prefix of s and strs[i] which is stored in s1 to s again.
        }
        return s1;
    }
};