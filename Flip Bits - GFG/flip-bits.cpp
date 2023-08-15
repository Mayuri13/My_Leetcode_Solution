//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        int ans = 0, sum = 0, cnt = 0;
        for(int i=0; i<n; i++){
            if(a[i]==0){
                sum++;
                ans = max(ans,sum);
            }
            else{
                if(sum>0) sum--;
                cnt++;
            }
        }
        return ans+cnt;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends