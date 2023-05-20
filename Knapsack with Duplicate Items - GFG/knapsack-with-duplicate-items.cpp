//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int n, int w, int val[], int wt[])
    {
        vector<int>curr(w+1,0);
       for(int j=wt[0]; j<=w; j++){
           curr[j] = ((int)j/wt[0])*val[0];
       }
       
       for(int i=1; i<n; i++){
           for(int j=0; j<=w; j++){
               int p=0;
               if(wt[i]<=j)
                    p = val[i] + curr[j-wt[i]];
                int np = curr[j];
                curr[j]=max(np,p);
           }
       }
       
       return curr[w];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends