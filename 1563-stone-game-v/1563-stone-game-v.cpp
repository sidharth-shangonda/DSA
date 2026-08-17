#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
    int memo[501][501];
    int pref[501];

    int solve(int i, int j) {
        if (i == j) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        int max_score = 0;
        for (int k = i; k < j; ++k) {
            int left_sum = pref[k + 1] - pref[i];
            int right_sum = pref[j + 1] - pref[k + 1];

            if (left_sum < right_sum) {
                max_score = max(max_score, left_sum + solve(i, k));
            } else if (left_sum > right_sum) {
                max_score = max(max_score, right_sum + solve(k + 1, j));
            } else {
                max_score = max(
                    max_score, 
                    left_sum + max(solve(i, k), solve(k + 1, j))
                );
            }
        }
        return memo[i][j] = max_score;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        pref[0] = 0;
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + stoneValue[i];
        }
        memset(memo, -1, sizeof(memo));
        return solve(0, n - 1);
    }
};
