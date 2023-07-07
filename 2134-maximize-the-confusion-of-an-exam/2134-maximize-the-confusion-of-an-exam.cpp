class Solution {
public:
    int maxConsecutiveAnswers(string a, int k) {
        int l = 0, cnt=0, ans=INT_MIN, op = k;
        char tmp1 = 'T', tmp2 = 'F';
        for(int i=0; i<a.size(); i++){
            if(a[i]!=tmp1){
                op--;
            }
            while(op<0){
                cnt--;
                if(a[l]!=tmp1){
                    op++;
                }
                l++;
            }
            cnt++;
            ans = max(ans,cnt);
        }
        cnt = 0, l = 0,op = k;
        for(int i=0; i<a.size(); i++){
            if(a[i]!=tmp2){
                op--;
            }
            while(op<0){
                cnt--;
                if(a[l]!=tmp2){
                    op++;
                }
                l++;
            }
            cnt++;
            ans = max(ans,cnt);
        }
        return ans;
    }
};