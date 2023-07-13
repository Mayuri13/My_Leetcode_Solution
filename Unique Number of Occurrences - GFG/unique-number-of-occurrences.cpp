//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        sort(arr,arr+n);
        set<int>st;
        int prev = arr[0], cnt=1;
        for(int i=1; i<n; i++){
            if(prev!=arr[i]){
                if(st.find(cnt)!=st.end())
                    return false;
                st.insert(cnt);
                cnt=1;
                prev = arr[i];
            }
            else{
                cnt++;
            }
        }
        if(st.find(cnt)!=st.end())
            return false;
        return true;
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
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends