class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total_xor = 0;
        bool has_nonzero = false;
        
        // Calculate total XOR and check if there are any non-zero elements
        for (int num : nums) {
            total_xor ^= num;
            if (num != 0) {
                has_nonzero = true;
            }
        }
        
        // Case 1: All elements are 0
        if (!has_nonzero) {
            return 0;
        }
        
        // Case 2: The XOR of all elements is already non-zero
        if (total_xor != 0) {
            return nums.size();
        }
        
        // Case 3: The total XOR is 0, removing one non-zero element fixes it
        return nums.size() - 1;
    }
};
