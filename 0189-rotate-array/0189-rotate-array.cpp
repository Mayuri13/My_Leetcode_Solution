class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        //Using reverse algorithm
        int n = nums.size();
        k %= n;

        //range of reverse function is, [first, last)
        reverse(nums.begin(), nums.begin() + (n-k));   //reverse from [0, 4) , i.e, excluidng 4th index
        reverse(nums.begin() + (n-k), nums.end());     //reverse from [4, 7) , i.e, excluidng 7th index
        reverse(nums.begin(), nums.end());
    }
};