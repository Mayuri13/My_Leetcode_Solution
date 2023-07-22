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
    int ans = INT_MIN;
    int find(TreeNode *root){
        if(root==NULL)
            return 0;
        int left = find(root->left), right = find(root->right);
        int sum = left + right;
        ans = max(ans,sum);
        return 1 + max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root->left==NULL && root->right==NULL)
            return 0;
        int res = find(root);
        return ans;
    }
};