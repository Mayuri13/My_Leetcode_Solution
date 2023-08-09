//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int n){
        long long ans = 2;
        while(n%2==0){
            n /= 2;
        }
        //now the number must be odd
        for(int i=3; i<=sqrt(n); i+=2){
            while(n%i==0){
                n /= i;
                ans = i;
            }
        }
        if(n>ans)
            return n;
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
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends