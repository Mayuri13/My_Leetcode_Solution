class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if(arr.size()==2)
            return true;
        sort(arr.begin(),arr.end());
        int d=arr[1]-arr[0];
        for(int i=2; i<arr.size(); i++){
            int temp = arr[i]-arr[i-1];
            if(d!=temp)
                return false;
        }
        return true;
    }
};