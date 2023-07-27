class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), k=-1, prev=INT_MIN;
        if(n==1 && gas[0]==cost[0])
            return 0;
        vector<pair<int,int>>val;
        for(int i=0; i<n; i++){
            int diff = gas[i]-cost[i];
            if(diff>0){
                if(i==n-1)
                    val.push_back({diff + gas[0],i});
                else
                    val.push_back({diff + gas[i+1],i});
                }
            
        }
        sort(val.begin(),val.end(),[](pair<int,int> a,pair<int,int> b){
            return a.first>b.first;
        });
        // for(int i=0; i<n; i++){
        //     if(gas[i]>=cost[i])
        //         val.push_back(i);
        // }
        for(int i=0; i<val.size(); i++){
            int cnt=0, j=val[i].second, tank=0;
            while(cnt<=n){
                if(j==n){
                    j=0;
                }
                tank+=gas[j];
                if(tank < cost[j])
                    break;
                tank-=cost[j++];
                cnt++;
            }
            if(cnt==n+1)
                return val[i].second;
        }
        return -1;
    }
};