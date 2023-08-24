//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string find(int n1, int n2, string s1, string s2){
        vector<int>vs(n1+n2+1,0);
        int k=-1, x= 0, c = 0;
        for(int i=n1-1; i>=0; i--){
            k++;
            x = k, c = 0;
            for(int j=n2-1; j>=0; j--){
                int prod = (s1[i]-'0')*(s2[j]-'0') + c;
                if(i==n1-1){
                    vs[x++] = prod%10; 
                    c = prod/10;
                    continue;
                }
                vs[x++] += prod%10; 
                c = prod/10;
            }
            if(c!=0)
                vs[x] = c;
        }
        string ans = to_string(vs[0]);
        c = 0;
        int j = vs.size()-1;
        
        while(vs[j]==0)
            j--;
            
        for(int i=1; i<=j; i++){
            vs[i] += c;
            ans += to_string(vs[i]%10);
            c = vs[i]/10;
        }
        if(c!=0)
            ans += to_string(c);
        return ans;
    }
    string multiplyStrings(string s1, string s2) {
        bool f1 = false, f2 = false;
        if(s1[0]=='-'){
            s1 = s1.substr(1,s1.size()-1);
            f1 = true;
        }
        if(s2[0]=='-'){
            s2 = s2.substr(1,s2.size()-1);
            f2 = true;
        }
       int n1 = s1.size(), n2 = s2.size();
       string ans="";
       if(n1>=n2){
           ans = find(n2,n1,s2,s1);
       }
       else{
           ans = find(n1,n2,s1,s2);
       }
       if(f1==f2){
        reverse(ans.begin(),ans.end());
        return ans;
       }
       ans.push_back('-');
       reverse(ans.begin(),ans.end());
       return  ans;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends