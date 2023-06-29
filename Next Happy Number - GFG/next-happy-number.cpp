//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int nextHappy(int N){
         if (N<7) return 7;
        while (true){
            int temp=++N;
            while (temp>6){
                int s=0;
                while (temp){
                    s+=(temp%10)*(temp%10);
                    temp/=10;
                }
                temp=s;
            }
            if (temp==1) return N;
        }
        return 0;
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
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends