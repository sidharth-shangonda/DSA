#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int counts[51] = {0};
        int n = nums.size();
        
        // Iterate through all possible subarrays of size k
        for (int i = 0; i <= n - k; ++i) {
            bool seen[51] = {false};
            
            // Mark which elements are present in the current subarray
            for (int j = i; j < i + k; ++j) {
                seen[nums[j]] = true;
            }
            
            // Increment the subarray occurrence count for those elements
            for (int x = 0; x <= 50; ++x) {
                if (seen[x]) {
                    counts[x]++;
                }
            }
        }
        
        int ans = -1;
        // Find the largest integer that appears in exactly 1 subarray
        for (int x = 0; x <= 50; ++x) {
            if (counts[x] == 1) {
                ans = max(ans, x);
            }
        }
        
        return ans;
    }
};
