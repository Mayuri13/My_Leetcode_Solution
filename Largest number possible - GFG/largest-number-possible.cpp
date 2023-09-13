//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        string ans = "";
        
        if(S==0 && N>1) return "-1";
        long long cnt = 9;
        while(N){
            cnt = 9;
            while(cnt > S){
                cnt--;
            }
            ans += to_string(cnt);
            S = S - cnt;
            N--;
            if(S==0) break;
        }
        ans.append(N,'0');
        if(S>0) return "-1";
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends