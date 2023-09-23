//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        if(n == 1) return 1;
        if(n == 2) return -1;
        int sum = 0, diff = 0;
        for(int i=0; i<n-2; i++){
            sum += a[i];
        }
        
        for(int i=n-1; i>=2; i--){
            diff += a[i];
            // cout<<diff<<" "<<sum<<endl;
            if(diff == sum) return i;
            sum -= a[i-2];
        }
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends