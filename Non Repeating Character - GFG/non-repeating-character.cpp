//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
        vector<int>dict(26,0);
        for(int i=0; i<S.size(); i++){
            dict[S[i]-'a']++;
        }
        char ans = '$';
        for(int i=0; i<S.size(); i++){
            if(dict[S[i]-'a']==1){
                ans = S[i];
                break;
            }
        }
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends