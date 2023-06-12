class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0)
            return {};
        if(nums.size()==1){
            string str = to_string(nums[0]);
            return {str};
        } 
        vector<string>ans;
        int s = 0, e = 0;
        for(int c=1; c<nums.size(); c++){

            if(nums[c] != nums[e]+1){
                if(s==e){
                    ans.push_back(to_string(nums[s++]));
                    e++;
                }
                else{
                    string str="";
                    str+=to_string(nums[s]);
                    str+="->";
                    str+=to_string(nums[e]);
                    ans.push_back(str);
                    s=e+1;
                    e++;
                }
            }
            else{
                e++;
            }
        }
            if(s==e){
                ans.push_back(to_string(nums[s++]));
            }
            else{
                string str="";
                str+=to_string(nums[s]);
                str+="->";
                str+=to_string(nums[e]);
                ans.push_back(str);
                }
        return ans;
    }
};