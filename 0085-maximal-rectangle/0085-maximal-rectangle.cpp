class Solution {
public:
    int largestRectangleArea(vector < int > & histo) {
      stack < int > st;
      int maxA = 0;
      int n = histo.size();
      for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
          int height = histo[st.top()];
          st.pop();
          int width;
          if (st.empty())
            width = i;
          else
            width = i - st.top() - 1;
          maxA = max(maxA, width * height);
        }
        st.push(i);
      }
      return maxA;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        vector<int>temp;
        for(int j=0; j<matrix[0].size(); j++){
            if(matrix[0][j]=='1')
                temp.push_back(1);
            else
                temp.push_back(0);
        }
        ans = max(ans,largestRectangleArea(temp));
        
        for(int i=1; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
               if(matrix[i][j]=='1')
                   temp[j]+=1;
                else
                    temp[j] = 0;
                
            }
            ans = max(ans,largestRectangleArea(temp));
        }
        return ans;
    }
};