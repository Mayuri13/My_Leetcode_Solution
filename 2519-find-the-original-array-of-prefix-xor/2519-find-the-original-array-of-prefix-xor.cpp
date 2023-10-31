class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int>v1;
        int x=pref[0];
        v1.push_back(pref[0]);
        for(int i=1; i<pref.size(); i++){
            x=x^pref[i];
            v1.push_back(x);
            x=pref[i];
        }
        return v1;
    }
};