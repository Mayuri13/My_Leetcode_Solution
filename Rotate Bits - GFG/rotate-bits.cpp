//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector<int> rotate (int n, int d)
    {
        //code here.
        d%=16;
        vector<int> res;
        int left=n,right=n;
        //right shift
        for(int i=0;i<16;i++)
        {
            if(n&(1<<i))
            {
                if(i>=d)
                {
                    right-=(1<<i);
                    right+=(1<<(i-d));
                }
                else
                {
                    right-=(1<<i);
                    right+=(1<<(15-(d-i)+1));
                }
            }
        }
        //left shift
        for(int i=0;i<=15;i++)
        {
            if(n&(1<<i))
            {
                if(i+d<=15)
                {
                    left-=(1<<i);
                    left+=(1<<(i+d));
                }
                else
                {
                    left-=(1<<i);
                    left+=(1<<(d-(15-i)-1));
                }
            }
        }
        res.push_back(left);
        res.push_back(right);
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends