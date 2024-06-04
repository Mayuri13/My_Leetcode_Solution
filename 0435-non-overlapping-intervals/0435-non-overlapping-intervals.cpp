class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        sort(inter.begin(), inter.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int end = inter[0][1];
        int count = 0;
        for (int i = 1; i < inter.size(); i++) {
            if (inter[i][0] < end) {
                count++;
            }
            else
                end = inter[i][1];
        }
        return count;
    }
};