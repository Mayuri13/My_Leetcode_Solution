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
    void find(TreeNode* root, vector<string>&ans, string str){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            str+=to_string(root->val);
            ans.push_back(str);
            return;
        }
        str = str + to_string(root->val) + '-' + '>';
        find(root->left,ans,str);
        find(root->right,ans,str);
        str.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string str = "";
        find(root,ans,str);
        return ans;
    }
};