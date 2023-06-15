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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>v;
        while(!q.empty()){
            int n = q.size(), sum=0;
            for(int i=0; i<n; i++){
                auto temp = q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
            }
            v.push_back(sum);
        }
        int mx = -1e6, k=-1;
        for(int i=0; i<v.size(); i++){
            if(v[i]>mx){
                mx = v[i];
                k = i;
            }
        }
        return k+1;
    }
};