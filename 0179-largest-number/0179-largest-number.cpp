class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>tmp;
        for(int i=0; i<nums.size(); i++){
            string str = to_string(nums[i]);
            tmp.push_back(str);
        }
        
        sort(tmp.begin(), tmp.end(), [](string &a, string &b){
            return a+b > b+a;
        });
        
        string ans = "";
        for(int i=0; i<tmp.size(); i++){
            ans += tmp[i];
        }
        
        int i = 0;
        while(i<ans.size() && ans[i]=='0'){
            i++;
        }
        // cout<<i
        if(i==ans.size()) return "0";
        
        return ans.substr(i);
    }
};