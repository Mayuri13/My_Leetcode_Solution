class Solution {
public:
    string reorganizeString(string s) {
        map<char,int>mp;
        string str="";
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }
        //implementing priority queue which stores the largest frequency element at the top
        priority_queue<pair<int,char>>q;
        for(auto x:mp){
            q.push({x.second,x.first});
        }
        
        //Reorganising the string
        while(!q.empty()){
            int freq = q.top().first;
            char a = q.top().second;
            q.pop();
            if(!str.empty() && str.back()==a){
                if(q.empty())
                    return "";
                int currF = q.top().first;
                char curr = q.top().second;
                q.pop();
                str+=curr;
                currF--;
                if(currF>0)
                    q.push({currF, curr});
            }
            else{
                str+=a;
                freq--;
            }
            if(freq>0)
                q.push({freq,a});
        }
        return str;
    }
};