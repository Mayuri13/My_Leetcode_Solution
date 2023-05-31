class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), mx = -1, k=-1;
        sort(nums.begin(), nums.end());
        
        vector<int>dp(n,1);
        vector<int>hash(n);
        for(int i=0; i<n; i++){
            hash[i] = i;
            for(int j=0; j<i; j++){
                if(((nums[i]%nums[j])==0) && (dp[i]<(1+dp[j]))){
                    dp[i] = 1+dp[j];
                    hash[i] = j;
                }
            }
        }
        for(int i=0; i<n; i++){
            if(mx<dp[i]){
                mx = dp[i];
                k=i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[k]);
    
        while(hash[k] != k){ // till not reach the initialization value
            k = hash[k];
            temp.push_back(nums[k]);    
        }
    
        // reverse the array 
        reverse(temp.begin(),temp.end());
        return temp;
        
    }
};