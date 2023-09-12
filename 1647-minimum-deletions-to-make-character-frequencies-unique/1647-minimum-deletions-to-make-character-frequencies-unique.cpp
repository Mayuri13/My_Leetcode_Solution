class Solution {
public:
    int minDeletions(string s) {
        //using Greedy
        //storing the frequency of the elements of the string in a vector
        vector<int>dict(26,0);
        for(int i=0; i<s.size(); i++){
            dict[s[i]-'a']++;
        }
        //sort the vector in non-decreasing order
        sort(dict.begin(), dict.end());
        
        int del = 0;
        for(int i=24; i>=0; i--){
            if(dict[i] == 0) break;
            if(dict[i] >= dict[i+1]){
                int prev = dict[i];
                dict[i] = max(0,dict[i+1]-1);
                del += prev - dict[i];
            }
        }
        return del;
    }
};