class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int n=nums.size();
       set<int>s;
       for(int i=0; i<n; i++){
           if(s.find(nums[i])!=s.end()){
               return nums[i];
           }
           else{
               s.insert(nums[i]);
           }
       }
       
       return 0;
    }
};