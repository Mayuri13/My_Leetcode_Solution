class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int>st;
        st.push(ast[0]);
        for(int i=1; i<ast.size(); i++){
            if(!st.empty() && (st.top()>0 && ast[i]<0)){
                int val = st.top(), flag=true;
                if(abs(ast[i])==abs(val))
                    st.pop();
                else if(abs(ast[i])<abs(val))
                    continue;
                else{
                    st.pop();
                    val = ast[i];
                    while(!st.empty()){
                        if((st.top()>0 && val>0) || (st.top()<0 && val<0)){
                            st.push(val);
                            break;
                        }
                        else if(st.top()>0 && val<0){
                            if(abs(st.top())<abs(val))
                                st.pop();
                            else if(abs(st.top())==abs(val)){
                                st.pop();
                                flag=false;
                                break;
                            }
                            else
                                break;
                        }
                    }
                    if(st.empty()==true && flag==true){
                        st.push(val);
                        continue;
                    }
                }
            }
            else{
                st.push(ast[i]);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};