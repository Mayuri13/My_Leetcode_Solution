/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* find(vector<int>& nums, int l, int r){
        if(l>r)
            return NULL;
        int mid = r - (r - l)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = find(nums,l,mid-1);
        root->right = find(nums,mid+1,r);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        return find(nums,l,r);
    }
};