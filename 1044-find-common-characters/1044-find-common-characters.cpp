class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>result;

        // Loop through each character from 'a' to 'z'
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int minCount = INT_MAX;
            
            // Count occurrences of the current character in each word
            for (string word : words) {
                int count = 0;
                for (char c : word) {
                    if (c == ch) {
                        count++;
                    }
                }
                minCount = min(minCount, count);
            }
            
            // Add the character to the result list the required number of times
            for (int i = 0; i < minCount; i++) {
                result.push_back(string(1,ch));
            }
        }
        return result;
    }
};