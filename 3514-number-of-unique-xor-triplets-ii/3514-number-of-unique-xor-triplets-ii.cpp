class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));
        dp[0][0] = true;

        // DP for XOR of exactly 3 distinct elements
        for (int x : nums) {
            for (int k = 2; k >= 0; k--) {
                for (int xr = 0; xr < MAXX; xr++) {
                    if (dp[k][xr]) {
                        dp[k + 1][xr ^ x] = true;
                    }
                }
            }
        }

        vector<bool> ans(MAXX, false);

        // All original values are always obtainable
        for (int x : nums)
            ans[x] = true;

        // Add XORs of 3 distinct elements
        for (int xr = 0; xr < MAXX; xr++)
            if (dp[3][xr])
                ans[xr] = true;

        int cnt = 0;
        for (bool x : ans)
            cnt += x;

        return cnt;
    }
};