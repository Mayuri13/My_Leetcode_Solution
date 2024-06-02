class Solution {
public:
    int mod = 1e9 + 7; 
    long long findPow(long long n, long long x){
        if(x == 0) return 1;
        if(x == 1) return n;

        long long ans = 1;
        while(x >= 1){
            if(x%2 == 0){
                n = (long long) (n * n)%mod;
                x /= 2;
            }
            else{
                ans = (long long) (ans * n)%mod;
                x--;
            }
        }
        return ans%mod;
    }

    int countGoodNumbers(long long n) {
    /*
        As digits will be from 0 - 9.
        if n == 5, there will be 5 digits at positions:
        0   1   2   3   4   5
        e   o   e   o   e   o

        there 5 even no.s from 0-9, [0,2,4,6,8]
        there are 4 prime no.s from 0-9, [2,3,5,7]
    */
        long long ans = 1;
        
        long long evenPow = n/2 + (n%2 != 0); 
        long long oddPow = n/2;

        ans *= (long long) findPow(5, evenPow);   //Recursive function for calculating 5^evenPow (comb of even places)
        ans *= (long long) findPow(4, oddPow);    //Recursive function for calculating 4^oddPow (comb of odd places)
        return ans % mod;
    }
};