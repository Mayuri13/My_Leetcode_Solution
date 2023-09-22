//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        int lo = 0, hi = n-1, first = -1, last = -1;
        while(lo <= hi){
            int mid = hi - (hi - lo)/2;
            if(arr[mid] == x){
                int i = mid;
                while(arr[i] == x){
                    i++;
                }
                last = i-1;
                i = mid;
                while(arr[i]==x){
                    i--;
                }
                first = i+1;
                break;
            }
            else if(arr[mid] < x)
                lo = mid+1;
            else
                hi = mid-1;
        }
        return {first, last};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends