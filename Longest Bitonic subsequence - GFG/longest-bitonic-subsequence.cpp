//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    int n = nums.size(), mx = 1, k = -1;
        vector<int>dp1(n,1);        //starting from 0th
        vector<int>dp2(n,1);        //in reverse direction
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i])
                    dp1[i] = max(dp1[i], 1+dp1[j]);
            }
        }
        for(int i=n-2; i>=0; i--){
            for(int j=n-1; j>i; j--){
                if(nums[j]<nums[i])
                    dp2[i] = max(dp2[i], 1+dp2[j]);
            }
        }
        for(int i=0; i<n; i++){
            mx = max(mx, dp1[i]+dp2[i]);
        }
        
        return mx-1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends