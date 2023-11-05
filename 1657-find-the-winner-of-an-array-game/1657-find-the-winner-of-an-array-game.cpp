class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        unordered_map<int, int> matchesWon;
        int n = arr.size();
        int currentMax = arr[0];  // Assume first element as max, but don't increment the "matchesWon" count.
        for (int i=1; i<n; i++) {
            currentMax = max(currentMax, arr[i]); // Match.
            matchesWon[currentMax]++;  // Increment the winner.
            if (matchesWon[currentMax] >= k) { // Check the matches won so far.
                return currentMax;
            }
        }
		// Didn't find the overall winner yet? Then the max element in the array will never lose, so ultimately
		// that number will be the winner.
        return currentMax;
    }
};