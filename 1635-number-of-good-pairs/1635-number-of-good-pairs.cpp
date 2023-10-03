class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size(),count=0;
        for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)               //2 3 1 1 2 3
        {
            if(nums[i]==nums[j])
                count++;
        }
    }
        return count;
    }
};