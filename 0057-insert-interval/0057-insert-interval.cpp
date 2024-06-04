class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>>ans;
        //If intervals is empty, then push newInterval and return
        if(intervals.size() == 0){
            ans.push_back(newInterval);
            return ans;
        }
        
        int k = -1;  //to store the index, before which the newInterval will be inserted
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i][0] < newInterval[0])  //If start of i interval is less then newInterval, then push it
                ans.push_back(intervals[i]);
            else{
                k = i;  //If start of i interval is greater then newInterval, then k = i, and break
                break;
            }
        }
        if(!ans.empty() && (ans.back()[1] >= newInterval[0])){
            ans.back()[1] = max(ans.back()[1], newInterval[1]);   //merge newInterval with the last interval inserted
        }
        else
            ans.push_back(newInterval);   
        

        //Merge the further remaining intervals
        for(int i=k; i<intervals.size(); i++){
            if(ans.back()[1] >= intervals[i][0]){
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};