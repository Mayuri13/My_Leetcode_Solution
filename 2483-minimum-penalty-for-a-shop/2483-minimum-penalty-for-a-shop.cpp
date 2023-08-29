class Solution {
public:
    int bestClosingTime(string cust) {
        vector<int>v(2,0);
        for(int i=0; i<cust.size(); i++){
            if(cust[i]=='Y')
                v[0]++;
        }
        int val = INT_MAX, k = -1;
        for(int i=0; i<cust.size(); i++){
            if(cust[i]=='N'){
                if(val>(v[0]+v[1])){
                    val = v[0]+v[1];
                    k = i;
                }
                v[1]++;
            }
            else{
                if(val>(v[0]+v[1])){
                    val = v[0]+v[1];
                    k = i;
                }
                v[0]--;
            }
        }
        if(val>(v[0]+v[1])){
            val = v[0]+v[1];
            k = cust.size();
        }
        return k;
    }
};