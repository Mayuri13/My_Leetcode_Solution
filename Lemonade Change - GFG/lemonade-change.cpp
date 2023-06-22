//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        if(bills[0]>5)
            return false;
        vector<int>cash(2,0);
        for(int i=0; i<N; i++){
            if(bills[i]==5){
                cash[0]++;
                continue;
            }
            else if(bills[i]==10){
                if(cash[0]>0){
                    cash[1]++;
                    cash[0]--;
                }
                else
                    return false;
            }
            else if(bills[i]==20){
                if(cash[0]==0)
                    return false;
                
                if(cash[1]>0){
                    cash[1]--;
                    cash[0]--;
                }
                else{
                    if(cash[0]<3)
                        return false;
                    cash[0]-=3;
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends