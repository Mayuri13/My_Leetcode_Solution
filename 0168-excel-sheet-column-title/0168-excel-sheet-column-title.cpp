class Solution {
public:
    string convertToTitle(int n) {
//         if(n<=26){
            
//         }
        string str = "";
        while(n>26){
            // cout<<n%26<<" ";
            if(n%26==0){
                str+='Z';
                n--;
            }
            else{
                char ch2 = static_cast<char>(64+(n%26));
                str += ch2;
            }
            n/=26;
        }
        // cout<<n;
        if(n<=26)
            str += static_cast<char>(64+n);
        reverse(str.begin(),str.end());
        return str;
    }
};