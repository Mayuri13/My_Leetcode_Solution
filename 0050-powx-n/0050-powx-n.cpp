class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long ex = n;
        if(ex < 0) ex = -1*ex;
        while(ex){
            if(ex % 2==0){
                x = x*x;
                ex/=2;
            }
            else{
                ans *= x;
                ex--;
            }
        }
        // ans *= x;
        if(n<0) 
            return (double)1.0/(double)ans;
        return ans;
    }
};