//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod = 1e9+7;
    int nCr(int n, int r){
        if(r>n)
            return 0;
        if(r==n)
            return 1;
        vector<int>prev(r+1,0),curr(r+1,0);
        prev[0]=prev[1]=1;
        for(int i=2; i<=n; i++){
            curr[0]=1;
            for(int j=1; j<=r; j++){
                curr[j] = (prev[j-1]+prev[j])%mod;
            }
            prev = curr;
        }
        return prev[r]%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends