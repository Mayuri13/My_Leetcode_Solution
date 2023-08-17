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
    bool find(TreeNode* root, TreeNode* sub){
        if(root==NULL && sub==NULL) return true;
        if(root==NULL && sub!=NULL) return false;
        if(root!=NULL && sub==NULL) return false;
        if(root->val != sub->val) return false;
        return find(root->left,sub->left) && find(root->right,sub->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* sub) {
        if(root==NULL)
            return false;
        bool res = false;
        if(root->val == sub->val)
            res = find(root,sub);
        return (isSubtree(root->left,sub) || isSubtree(root->right,sub)) || res;
    }
};