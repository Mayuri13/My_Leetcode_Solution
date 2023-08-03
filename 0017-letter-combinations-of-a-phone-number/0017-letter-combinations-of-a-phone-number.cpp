class Solution {
public:
    void find(int idx, string str, string digits, map<int,string>&mp, int n, vector<string>&ans){
        if(idx==n){
            ans.push_back(str);
            return;
        }
        string val = mp[digits[idx]-'0'];
        for(auto it:val){
            str+= it;
            find(idx+1,str,digits,mp,n,ans);
            str.pop_back();
        }
        return;
    }
    
    vector<string> letterCombinations(string digits) {
        int n = digits.size(), cnt=0;
        if(n==0)
            return {};
        vector<string>ans;
        string str="";
        map<int,string>mp = {{2,"abc"},
                             {3,"def"},
                             {4,"ghi"},
                             {5,"jkl"},
                             {6,"mno"},
                             {7,"pqrs"},
                             {8,"tuv"},
                             {9,"wxyz"}};
        find(0,str,digits,mp,n,ans);
        return ans;
    }
};