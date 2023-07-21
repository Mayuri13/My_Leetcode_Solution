class Solution {
public:
    int area(vector<int>&hist){
        int n = hist.size();
        //LS (storing left small indices for each element of hist)
        stack<int>st;
        vector<int>LS(n);
        for(int i=0; i<n; i++){
            while(!st.empty() && hist[st.top()]>=hist[i]){
                st.pop();
            }
                
            if(st.empty())
                LS[i] = 0;
            else
                LS[i] = st.top()+1;
            st.push(i);
        }
        while(!st.empty()){
            st.pop();   
        }
        //RS (storing right small indices for each element of hist)
        vector<int>RS(n);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && hist[st.top()]>=hist[i]){
                st.pop();
            }
                
            if(st.empty())
                RS[i] = n-1;
            else
                RS[i] = st.top()-1;
            st.push(i);
        }
        int mxArea = 0;
        for(int i=0; i<n; i++){
            mxArea = max(mxArea, (RS[i]-LS[i]+1)*hist[i]);
        }
        return mxArea;
    }

    int maximalRectangle(vector<vector<char>>& mat) {
        vector<int>hist;
        for(int j=0; j<mat[0].size(); j++){
            if(mat[0][j]=='1')
                hist.push_back(1);
            else
                hist.push_back(0);
        }
        int mx = INT_MIN;
        mx = max(mx,area(hist));
        for(int i=1; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]=='1')
                    hist[j]++;
                else
                    hist[j]=0;
            }
            mx = max(mx,area(hist));
        }
        return mx;
    }
};