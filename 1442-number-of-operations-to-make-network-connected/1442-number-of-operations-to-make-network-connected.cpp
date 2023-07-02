class DisjointSet
{
    //declaring the constructor
    public:
    vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i]=i;
        }
    }
    //Utimate parent finding function
    int findUPar(int node){
        if(node==parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    //union by size function
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& c) {
        int exEdj=0;
        DisjointSet ds(n);
        for(int i=0; i<c.size(); i++){
            int u = c[i][0];
            int v = c[i][1];
            if(ds.findUPar(u)!=ds.findUPar(v)){
                ds.unionBySize(u,v);
            }
            else
                exEdj++;
        }
        int nc=0;
        for(int i=0; i<n; i++){
            //no. of ultimate parents will determine no. of components 
            if(ds.parent[i]==i)
                nc++;
        }
        if(exEdj<nc-1)
            return -1;
        return nc-1;
    }
};