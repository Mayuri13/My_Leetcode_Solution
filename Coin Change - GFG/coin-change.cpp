//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int n, int amount) {
        vector<long long int>prev(amount+1,0), curr(amount+1,0);
        for(int j=0; j<=amount; j++){
            if(j%coins[0]==0) 
                prev[j]=1;
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<=amount; j++){
                long long int p = 0;
                if(coins[i]<=j)
                    p = curr[j-coins[i]];
                long long int np = prev[j];
                curr[j]=np+p;
            }
            prev = curr;
        }
        return prev[amount];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends