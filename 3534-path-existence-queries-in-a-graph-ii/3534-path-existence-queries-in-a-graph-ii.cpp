#include <vector>
#include <algorithm>
#include <array>

using namespace std;

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int max_val = 0;
        for (int x : nums) {
            if (x > max_val) max_val = x;
        }
        
        // S will hold the sorted unique values to build our 1D Value Graph
        vector<int> S = nums;
        sort(S.begin(), S.end());
        S.erase(unique(S.begin(), S.end()), S.end());
        
        int k = S.size();
        
        // Fast O(1) map from the value in nums to its index representation in S
        vector<int> val_to_idx(max_val + 1, -1);
        for(int i = 0; i < k; ++i) {
            val_to_idx[S[i]] = i;
        }
        
        // Pre-compute components to quickly spot isolated partitions 
        vector<int> comp(k, 0);
        int c = 0;
        comp[0] = 0;
        for(int i = 1; i < k; ++i) {
            if (S[i] - S[i-1] > maxDiff) {
                c++;
            }
            comp[i] = c;
        }
        
        // Binary Lifting table formulation to fast-forward querying
        int LOG = 18;
        vector<array<int, 18>> up(k);
        int j = 0;
        
        for(int i = 0; i < k; ++i) {
            // Find the furthest reachable node from `i` safely bounded within `maxDiff`
            while(j + 1 < k && S[j+1] <= S[i] + maxDiff) {
                j++;
            }
            up[i][0] = j;
        }
        
        // Populate the 2^p jump positions
        for(int p = 1; p < LOG; ++p) {
            for(int i = 0; i < k; ++i) {
                up[i][p] = up[up[i][p-1]][p-1];
            }
        }
        
        int q = queries.size();
        vector<int> ans(q);
        
        for(int i = 0; i < q; ++i) {
            int u = queries[i][0];
            int v = queries[i][1];
            
            if (u == v) {
                ans[i] = 0;
                continue;
            }
            
            int val_u = nums[u];
            int val_v = nums[v];
            
            // They possess the same values but act as discrete connected nodes
            if (val_u == val_v) {
                ans[i] = 1;
                continue;
            }
            
            // Normalize direction to always travel lower to higher (Rightward jump mapping setup)
            if (val_u > val_v) {
                swap(val_u, val_v);
            }
            
            int idx_u = val_to_idx[val_u];
            int idx_v = val_to_idx[val_v];
            
            // Belonging to different components indicates an unbridgeable gap exists
            if (comp[idx_u] != comp[idx_v]) {
                ans[i] = -1;
                continue;
            }
            
            int curr = idx_u;
            int steps = 0;
            
            // Jump by leveraging the greatest powers of 2 mapping strictly below target
            for (int p = LOG - 1; p >= 0; --p) {
                if (up[curr][p] < idx_v) {
                    curr = up[curr][p];
                    steps += (1 << p);
                }
            }
            
            // Reaching this state means taking precisely `steps` length jumps puts us < `idx_v`.
            // Just 1 final jump connects natively to/past `idx_v` mapping resolving shortest path natively. 
            steps += 1;
            ans[i] = steps;
        }
        
        return ans;
    }
};