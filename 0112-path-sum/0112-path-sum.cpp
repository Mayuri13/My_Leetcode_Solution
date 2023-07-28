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
    bool find(TreeNode* root, int tar){
        if(root==NULL)
            return false;
        
        if(root->left==NULL && root->right==NULL){
            if(tar==root->val)
                return true;
            return false;
        }
        return (find(root->left,tar-root->val) || find(root->right,tar-root->val));
    }
    bool hasPathSum(TreeNode* root, int tar) {
        if(root==NULL)
            return false;
        return find(root,tar);
    }
};