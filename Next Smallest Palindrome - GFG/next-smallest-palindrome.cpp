//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> generateNextPalindrome(int num[], int n) {
	     int mid=(n-1)/2;
        bool find=false;
        for(int i=mid+1;i<n;i++){
            if(num[i]==num[n-i-1]) continue;
            if(num[i]<num[n-i-1]){
                find=true;
                break;
            }
            else{
                break;
            }
        }
        if(find){
            for(int i=mid+1;i<n;i++){
                num[i]=num[n-i-1];
            }
            vector<int> res(n);
            for(int i=0;i<n;i++) res[i]=num[i];
            return res;
        }
        int idx=-1;
        for(int i=mid;i>=0;i--){
            if(num[i]<9){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            bool find1=false;
            for(int i=mid+1;i<n;i++){
                if(num[i]!=9){
                    find1=true;
                    break;
                }
            }
            if(find1){
                vector<int> res(n,9);
                return res;
            }
            vector<int> res(n+1,0);
            res[0]=1;res[n]=1;
            return res;
        }
        num[idx]+=1;
        for(int i=idx+1;i<=mid;i++) num[i]=0;
        for(int i=mid+1;i<n;i++){
            num[i]=num[n-i-1];
        }
        vector<int> res(n);
        for(int i=0;i<n;i++) res[i]=num[i];
        return res;
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends