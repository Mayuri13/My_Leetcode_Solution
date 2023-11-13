class Solution {
public:
    string sortVowels(string s) {
        priority_queue <char, vector<char>, greater<char>> pq;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='a' || s[i]=='e'|| s[i]=='i'|| s[i]=='o'|| s[i]=='u'|| s[i]=='A'|| s[i]=='E'|| s[i]=='I'|| s[i]=='O'|| s[i]=='U')
                pq.push(s[i]);
        }
        string ans="";
        for(int i=0; i<s.size(); i++){
            if(s[i]=='a' || s[i]=='e'|| s[i]=='i'|| s[i]=='o'|| s[i]=='u'|| s[i]=='A'|| s[i]=='E'|| s[i]=='I'|| s[i]=='O'|| s[i]=='U'){
                char tmp = pq.top();
                pq.pop();
                ans+=tmp;
            }
            else
                ans+=s[i];
        }
        return ans;
    }
};