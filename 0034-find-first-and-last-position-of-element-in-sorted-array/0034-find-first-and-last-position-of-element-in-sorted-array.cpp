class Solution {
public:
    int findF(vector<int>& nums,int l,int h,int x){
         int n=nums.size();
        while(l<=h){
            int m=(l+h)/2;
            if(nums[m]>x)h=m-1;
            else if(nums[m]<x)l=m+1;
            else{
                if(m==0 || nums[m-1]!=nums[m])return m;
                else
                    h=m-1;
            }
        }
        return -1;
    }
    int findL(vector<int>&nums,int l,int h,int x){
         int n=nums.size();
        while(l<=h){
            int m=(l+h)/2;
            if(nums[m]>x)h=m-1;
            else if(nums[m]<x)l=m+1;
            else{
                if(m==n-1 || nums[m+1]!=nums[m])return m;
                else
                    l=m+1;
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
         int n=nums.size();
         vector<int>ans;
        ans.push_back(findF(nums,0,n-1,target));
        ans.push_back(findL(nums,0,n-1,target));
        return ans;
    }
};