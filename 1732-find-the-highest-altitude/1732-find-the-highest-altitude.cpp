class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int a = 0, temp=0;
        for(int i=0; i<gain.size(); i++){
            temp += gain[i];
            a = max(a,temp);
        }
        return a;
    }
};