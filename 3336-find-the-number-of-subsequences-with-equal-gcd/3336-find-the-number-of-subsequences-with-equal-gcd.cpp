#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int MOD = 1e9 + 7;
        int max_val = 0;
        
        // Step 1: Find the upper bound for our DP table
        for (int x : nums) {
            max_val = max(max_val, x);
        }
        
        // Step 2: Precompute all possible GCDs. 
        // This prevents expensive standard library calls inside our 3D loop.
        vector<vector<int>> gcd_table(max_val + 1, vector<int>(max_val + 1, 0));
        for (int i = 0; i <= max_val; ++i) {
            for (int j = 0; j <= max_val; ++j) {
                if (i == 0) gcd_table[i][j] = j; // GCD of 0 and X is X
                else if (j == 0) gcd_table[i][j] = i;
                else gcd_table[i][j] = std::gcd(i, j);
            }
        }

        // Step 3: Setup the DP table. 
        // dp[g1][g2] stores the number of ways to have seq1 with GCD g1 and seq2 with GCD g2.
        vector<vector<int>> dp(max_val + 1, vector<int>(max_val + 1, 0));
        
        // Base state: 1 way to have two empty subsequences (represented by GCD 0)
        dp[0][0] = 1;

        // Step 4: Process each number in the array one by one
        for (int x : nums) {
            // Copy current states to next_dp. This automatically handles the "Ignore 'x'" choice.
            vector<vector<int>> next_dp = dp; 
            
            for (int g1 = 0; g1 <= max_val; ++g1) {
                for (int g2 = 0; g2 <= max_val; ++g2) {
                    
                    // If this state has valid subsequences, branch out
                    if (dp[g1][g2] > 0) {
                        int ways = dp[g1][g2];
                        
                        // Choice A: Add 'x' to the first subsequence
                        int n_g1 = gcd_table[g1][x];
                        next_dp[n_g1][g2] = (next_dp[n_g1][g2] + ways) % MOD;
                        
                        // Choice B: Add 'x' to the second subsequence
                        int n_g2 = gcd_table[g2][x];
                        next_dp[g1][n_g2] = (next_dp[g1][n_g2] + ways) % MOD;
                    }
                }
            }
            // Overwrite old states with the newly calculated states
            dp = next_dp;
        }

        // Step 5: Tally up all pairs where the GCDs match and are greater than 0
        int ans = 0;
        for (int g = 1; g <= max_val; ++g) {
            ans = (ans + dp[g][g]) % MOD;
        }
        
        return ans;
    }
};