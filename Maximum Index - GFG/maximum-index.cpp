//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        if(n==1)
            return 0;
        vector<int>mini(n), maxi(n);
        int prev=arr[0];
        mini[0] = prev;
        for(int i=1; i<n; i++){
            prev = min(prev,arr[i]);
            mini[i] = prev;
        }
        prev = arr[n-1];
        maxi[n-1] = prev;
        for(int i=n-2;i>=0; i--){
            prev = max(prev,arr[i]);
            maxi[i] = prev;
        }
        int ans = -1, i=0, j=0;
        while(i<n && j<n){
            if(mini[i]<=maxi[j]){
                ans = max(ans,j-i);
                j++;
            }
            else
                i++;
        }
        return ans;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends