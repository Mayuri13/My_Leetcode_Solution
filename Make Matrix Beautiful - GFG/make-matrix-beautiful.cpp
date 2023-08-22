//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        int rsum = 0, csum = 0, ans = 0;
        for(int i=0; i<n; i++){
            int tmp1 = 0, tmp2 = 0;
            for(int j=0; j<n; j++){
                tmp1 += matrix[i][j];
                tmp2 += matrix[j][i];
            }
            rsum = max(rsum,tmp1);
            csum = max(csum,tmp2);
        } 
        if(rsum>=csum){
            for(int i = 0; i<n; i++){
                int tmp1 = 0;
                for(int j=0; j<n; j++){
                    tmp1 += matrix[i][j];
                }
                if(rsum!=tmp1)
                    ans+=rsum-tmp1;
            }
        }
        else{
            for(int i = 0; i<n; i++){
                int tmp2 = 0;
                for(int j=0; j<n; j++){
                    tmp2 += matrix[j][i];
                }
                if(csum!=tmp2)
                    ans+=csum-tmp2;
            }
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends