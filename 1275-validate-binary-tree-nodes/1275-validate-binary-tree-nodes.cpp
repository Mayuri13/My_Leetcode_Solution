class Solution {
public:
    bool find(int root, vector<int>& lc, vector<int>& rc, set<int>&s, vector<int>&vis){
        if(vis[root]) return false;
        if(s.find(root)!=s.end()) return false;
        // if(dp[root]) return true;
        s.insert(root);
        vis[root] = 1;
        bool left = true, right = true;
        if(lc[root]!=-1) 
            left = find(lc[root],lc,rc,s,vis);
        if(rc[root]!=-1)
            right = find(rc[root],lc,rc,s,vis);
        return left && right;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& lc, vector<int>& rc) {
        // vector<bool>dp(n,false);
        set<int>s1;
        set<int>s;
        for(int i=0; i<n; i++){
            s1.insert(i);
        }
        for(int i=0; i<n; i++){
            if(lc[i]!=-1 && s1.find(lc[i])!=s1.end()) s1.erase(lc[i]);
            if(rc[i]!=-1 && s1.find(rc[i])!=s1.end()) s1.erase(rc[i]);
        }
        if(s1.empty() || s1.size()>1) return false;
        auto it = s1.begin();
        int root = *it;
        vector<int>vis(n,0);
        bool ans = find(root,lc,rc,s,vis);
        for(int i=0; i<n; i++){
            if(!vis[i]) return false;
        }
        return ans;
    }
};