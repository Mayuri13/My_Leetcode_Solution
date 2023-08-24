class Solution {
public:
    string reorderSpaces(string text) {
        string str="";
        int cnt=0;
        vector<string>vs;
        for(int i=0; i<text.size(); i++){
            if(text[i]==' '){
                cnt++;
                if(!str.empty()){
                    vs.push_back(str);
                    str="";
                }
                continue;
            }
            str += text[i];
        }
        if(!str.empty())
            vs.push_back(str);
        int n = vs.size();
        if(n==1){
            if(cnt==0)
                return text;
            else{
                str ="";
                str += vs[0];
                for(int j=0; j<cnt; j++)
                    str += " ";
                return str;
            }
        }
        int val = cnt/(n-1), rem = cnt%(n-1);
        string ans="";
        for(int i=0; i<n-1; i++){
            ans+=vs[i];
            for(int j=0; j<val; j++)
                ans+=" ";
        }
        ans += vs[n-1];
        while(rem>0){
            ans+=" ";
            rem--;
        }
        return ans;
    }
};