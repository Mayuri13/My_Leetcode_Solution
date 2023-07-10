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
    int find(TreeNode* root){
        if(root->left==NULL && root->right==NULL){
            return 0;
        }
        int l=1e9, r=1e9;
        if(root->left!=NULL)
            l = 1 + find(root->left);
        if(root->right!=NULL)
            r = 1 + find(root->right);
        cout<<l<<" "<<r<<endl;
        return min(l,r);
    }
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        return 1 + find(root);
    }
};