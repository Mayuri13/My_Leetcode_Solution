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
    void helper(TreeNode* node, vector<int>& solution, int cl) {
        if (node == NULL) {
            return;
        }
        if (solution.size() < cl + 1) {
            solution.push_back(node->val);
        } else {
            if (solution[cl] < node->val) {
                solution[cl] = node->val;
            }
        }
        helper(node->left, solution, cl+1);
        helper(node->right, solution, cl+1);
    }
    //vector<int> largestValues(TreeNode* root) {
    vector<int> largestValues(TreeNode* root) {
        vector<int> solution;
        if(root == NULL) {
            return solution;
        }
        
        helper(root, solution, 0);
        return solution;
    }
};