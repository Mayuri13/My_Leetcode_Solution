//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        vector<vector<int>>ans;
        sort(arr.begin(), arr.end());
        set<vector<int>>st;
        int n = arr.size();
        for(int i=0; i<n; i++){
            vector<int>v;
            int val = k;
            v.push_back(arr[i]);
            val -= arr[i];

            for(int j=i+1; j<n; j++){
                v.push_back(arr[j]);
                val -= arr[j];
                
                int s = j+1, e = n-1;
                while(s < e){
                    if((arr[s] + arr[e]) < val)
                        s++;
                    else if((arr[s] + arr[e]) > val)
                        e--;
                    else{
                        v.push_back(arr[s]);
                        v.push_back(arr[e]);
                        if(st.find(v) == st.end())
                            st.insert(v);
                        v.pop_back();
                        v.pop_back();
                        s++;
                        e--;
                    }
                }
                v.pop_back();
                val += arr[j];
            }
        }
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends