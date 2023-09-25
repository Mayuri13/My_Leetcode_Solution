//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int n, int K, vector<int> &A, vector<int> &B) {
        priority_queue<pair<int,pair<int,int>>>pq;
        vector<int>ans;
        set<pair<int,int>>s;
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        pq.push({A[n-1]+B[n-1], {n-1, n-1}});
        s.insert({n-1,n-1});
        while(!pq.empty()){
            int sum = pq.top().first;
            int i = pq.top().second.first, j = pq.top().second.second;
            pq.pop();
            ans.push_back(sum);
            if(i-1 >=0 && s.find({i-1,j})==s.end()){
                pq.push({A[i-1]+B[j],{i-1,j}});
                s.insert({i-1,j});
            }
            if(j-1 >=0 && s.find({i,j-1})==s.end()){
                pq.push({A[i]+B[j-1],{i,j-1}});
                s.insert({i, j-1});
            }
                
            if(ans.size() == K)
                break;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends