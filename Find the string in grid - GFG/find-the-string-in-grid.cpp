//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int dx[8] = {1,1,1,-1,-1,-1,0,0};
    int dy[8] = {-1,0,1,-1,0,1,-1,1};
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    vector<vector<int>>ans;
	    int n = grid.size(), m = grid[0].size(), k = word.size();
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            if(grid[i][j]!=word[0]) continue;
	            for(int x=0; x<8; x++){
	                int sz = 1;
	                int ni = i+dx[x], nj = j+dy[x];
	                while(ni>=0 && ni<n && nj>=0 && nj<m && sz<k){
	                    if(grid[ni][nj]!=word[sz]) break;
	                    ni += dx[x];
	                    nj += dy[x];
	                    sz++;
	                }
	                if(sz==k){
	                    ans.push_back({i,j});
	                    break;
	                }
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends