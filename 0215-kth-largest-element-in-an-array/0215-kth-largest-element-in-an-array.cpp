class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        //Min heap to store k elements with max values in increasing order, so that top element is the kth largest
        priority_queue<int, vector<int>, greater<int>>pq;

        for(int i=0; i<nums.size(); i++){
            //If top element is less than nums[i], then pop bcz we need max valued elements in pq
            if(!pq.empty() && pq.size()==k && pq.top()<nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
            else if(pq.size()<k)
                pq.push(nums[i]);
        }
        return pq.top();
    }
};