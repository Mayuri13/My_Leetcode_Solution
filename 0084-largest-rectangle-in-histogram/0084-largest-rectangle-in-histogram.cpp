class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size(), ans = -1;
        vector<int>ls(n), rs(n);
        stack<int>st;
        //For left small
        for(int i=0; i<n; i++){
            while(!st.empty()){
                int x = st.top();
                if(h[x]>=h[i])
                    st.pop();
                else{
                    st.push(i);
                    ls[i] = x+1;
                    break;
                }
            }
            if(st.empty()){
                st.push(i);
                ls[i] = 0;
            }
        }
        while(!st.empty())
            st.pop();
        //For right small
        for(int i=n-1; i>=0; i--){
            while(!st.empty()){
                int x = st.top();
                if(h[x]>=h[i])
                    st.pop();
                else{
                    st.push(i);
                    rs[i] = x-1;
                    break;
                }
            }
            if(st.empty()){
                st.push(i);
                rs[i] = n-1;
            }
        }
        for(int i=0; i<n; i++){
            int area = (rs[i]-ls[i]+1)*h[i];
            ans = max(ans,area);
        }
        return ans;
    }
    
    
    //Naive Solution
    // int largestRectangleArea(vector<int>& heights) {
    //     int ans = -1;
    //     for(int i=0; i<heights.size(); i++){
    //         int j = i-1, k = i+1, area=heights[i];
    //         while(j>=0){
    //             if(heights[j--]>=heights[i]){
    //                 area+= heights[i];
    //             }
    //             else
    //                 break;
    //         }
    //         while(k<heights.size()){
    //             if(heights[k++]>=heights[i]){
    //                 area+= heights[i];
    //             }
    //             else
    //                 break;
    //         }
    //         ans = max(ans,area);
    //     }
    //     return ans;
    // }
};