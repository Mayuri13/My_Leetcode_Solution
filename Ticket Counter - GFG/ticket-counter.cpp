//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        deque<int>dq;
        for(int i=1; i<=N; i++){
            dq.push_back(i);
        }
        while(dq.size()>1){
            for(int j=0; j<K && dq.size()>1; j++){
                dq.pop_front();
            }
            for(int j=0; j<K && dq.size()>1; j++){
                dq.pop_back();
            }
            
        }
        return dq.front();
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends