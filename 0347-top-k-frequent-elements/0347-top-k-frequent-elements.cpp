class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        map<int,int>mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto x:mp){
            pq.push({x.second,x.first});
        }
        int j=0;
        while(j<k){
            int val = pq.top().second;
            pq.pop();
            ans.push_back(val);
            j++;
        }
        return ans;
    }
};