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
    TreeNode* rev(TreeNode *root){
        if(root==NULL)
            return NULL;
        TreeNode *ls =rev(root->left);
        TreeNode *rs = rev(root->right);
        root->left = rs;
        root->right = ls;
        return root;  
    }
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* tmp = rev(root);
        return root;
    }
};