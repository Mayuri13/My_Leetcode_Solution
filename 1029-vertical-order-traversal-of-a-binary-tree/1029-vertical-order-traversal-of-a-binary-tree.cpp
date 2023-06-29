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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<int,vector<int>>mp;
        queue<pair<int,TreeNode*>>q;
        q.push({0,root});
        while(!q.empty()){
            multiset<pair<int,int>>s;
            int n = q.size();
            for(int i=0; i<n; i++){
                int x = q.front().first;
                TreeNode* node = q.front().second;
                q.pop();
                s.insert({node->val,x});
                if(node->left!=NULL)
                    q.push({x-1,node->left});
                if(node->right!=NULL)
                    q.push({x+1,node->right});
            }
            for(auto x:s){
                mp[x.second].push_back(x.first);
            }  
        }
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};