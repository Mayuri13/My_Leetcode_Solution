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
    vector<TreeNode*> build(int start, int end){
        if(start>end) return {NULL};
        if(start==end) return {new TreeNode(start)};
        
        vector<TreeNode*> ans;
        for(int i=start;i<=end;i++){
            // inorder of BST is sorted i.e left -> root-> right
            vector<TreeNode*> left=build(start,i-1);
            vector<TreeNode*> right=build(i+1,end);
            
            // building all possible combinations with left having smaller than root & right having bigger values than root
            for(TreeNode* l : left){
                for(TreeNode* r : right){
                    TreeNode* root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return build(1,n);
    }
};