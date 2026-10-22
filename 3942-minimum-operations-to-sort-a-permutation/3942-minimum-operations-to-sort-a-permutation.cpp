class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int idx = 0;

        // Find the index of 0
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                idx = i;
                break;
            }
        }

        // Check circular order in either direction
        auto check = [&](int step) -> bool {
            for (int i = 1; i < n; i++) {
                int prev = (idx + (i - 1) * step % n + n) % n;
                int curr = (idx + i * step % n + n) % n;

                if (nums[curr] != (nums[prev] + 1) % n) {
                    return false;
                }
            }
            return true;
        };

        int ans = INT_MAX;

        // Increasing circular order
        if (check(1)) {
            ans = min(ans, idx);
            ans = min(ans, n - idx + 2);
        }

        // Decreasing circular order
        if (check(-1)) {
            ans = min(ans, idx + 2);
            ans = min(ans, n - idx);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};