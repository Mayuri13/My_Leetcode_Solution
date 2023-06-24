class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int>:: iterator it;
        it=unique(nums.begin(),nums.begin()+n);
        nums.resize(distance(nums.begin(),it));
        int k=nums.size();
        return k;
    }
};