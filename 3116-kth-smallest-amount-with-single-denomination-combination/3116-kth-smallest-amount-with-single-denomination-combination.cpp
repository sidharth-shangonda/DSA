class Solution {
    // Helper function to calculate GCD to avoid standard library compatibility issues
    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            std::swap(a, b);
        }
        return a;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        // Step 1: Sort and filter out redundant coins
        std::sort(coins.begin(), coins.end());
        std::vector<int> filtered_coins;
        for (int c : coins) {
            bool keep = true;
            for (int fc : filtered_coins) {
                if (c % fc == 0) {
                    keep = false;
                    break;
                }
            }
            if (keep) {
                filtered_coins.push_back(c);
            }
        }
        
        // Define the theoretical maximum bounds for the binary search
        long long max_x = (long long)filtered_coins[0] * k;
        
        // Step 2: Precalculate all inclusion and exclusion denominators (LCMs)
        std::vector<long long> add, sub;
        int n = filtered_coins.size();
        
        // Loop through all 2^N - 1 non-empty subsets utilizing bitmasking
        for (int mask = 1; mask < (1 << n); ++mask) {
            long long cur_lcm = 1;
            int bits = 0;
            
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    bits++;
                    long long g = gcd(cur_lcm, (long long)filtered_coins[i]);
                    
                    // Prevent large bounds overflow for sets with massive LCMs
                    if (cur_lcm / g > max_x / filtered_coins[i]) {
                        cur_lcm = max_x + 1; // Mark as safely out of bounds
                        break;
                    }
                    cur_lcm = (cur_lcm / g) * filtered_coins[i];
                }
            }
            
            // Collect the valid LCMs depending on their subset sizes (PIE rule)
            if (cur_lcm <= max_x) {
                if (bits % 2 == 1) {
                    add.push_back(cur_lcm);
                } else {
                    sub.push_back(cur_lcm);
                }
            }
        }
        
        // Step 3: Execute Binary Search
        long long low = 1, high = max_x, ans = max_x;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long count = 0;
            
            // Rapidly count multiples using PIE subsets
            for (long long a : add) count += mid / a;
            for (long long s : sub) count -= mid / s;
            
            if (count >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};
