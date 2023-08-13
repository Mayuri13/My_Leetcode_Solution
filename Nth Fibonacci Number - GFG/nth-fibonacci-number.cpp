//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        if(n<3)
            return 1;
        int mod = 1e9+7;
        int prev1 = 1, prev2 = 1;
        for(int i=3; i<=n; i++){
            int curr = (prev1 + prev2)%mod;
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends