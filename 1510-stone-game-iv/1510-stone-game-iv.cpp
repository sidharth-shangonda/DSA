class Solution {
public:
    bool winnerSquareGame(int n) {
        // Create a boolean array of size n+1, initialized to false
        vector<bool> dp(n + 1, false);
        
        // Calculate the winner for every pile size from 1 to n
        for (int i = 1; i <= n; i++) {
            // Try removing every perfect square (k*k) less than or equal to i
            for (int k = 1; k * k <= i; k++) {
                // If this move leaves the opponent in a losing state (false)
                if (!dp[i - k * k]) {
                    dp[i] = true; // The current player wins
                    break;        // No need to check other moves for this i
                }
            }
        }
        
        // Return the result for the full pile size
        return dp[n];
    }
};
