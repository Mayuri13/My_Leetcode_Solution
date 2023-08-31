class Solution {
public:
    //recursive solution
    bool find(int i, vector<int>& vis, vector<int>& arr){
        if(i>=arr.size() || i<0) return false;
        if(vis[i]) return false;
        if(arr[i]==0) return true;
        vis[i] = 1;
        return find(i+arr[i],vis,arr) || find(i-arr[i],vis,arr);
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int>vis(n,0);
        return find(start,vis,arr);
    }
};