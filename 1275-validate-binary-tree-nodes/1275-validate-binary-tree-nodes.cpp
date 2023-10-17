class Solution {
public:
    bool find(int root, vector<int>& lc, vector<int>& rc, set<int>&s){
        if(s.find(root)!=s.end()) return false;
        s.insert(root);
        bool left = true, right = true;
        if(lc[root]!=-1) 
            left = find(lc[root],lc,rc,s);
        if(rc[root]!=-1)
            right = find(rc[root],lc,rc,s);
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
        bool ans = find(root,lc,rc,s);
        if(s.size() != n) return false;
        return ans;
    }
};