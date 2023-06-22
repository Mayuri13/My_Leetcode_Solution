class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>mp(wordList.begin(),wordList.end());
        while(!q.empty()){
            string word = q.front().first;
            int dis = q.front().second;
            q.pop();
            if(word==endWord)
                return dis;
            for(int i=0; i<word.size(); i++){
                char original = word[i];
                for(char ch = 'a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(mp.find(word)!=mp.end()){
                        mp.erase(word);
                        q.push({word,dis+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};