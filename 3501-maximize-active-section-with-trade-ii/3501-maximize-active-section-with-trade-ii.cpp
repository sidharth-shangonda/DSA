#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int total_ones = 0;
        
        // Count the base number of '1's in the entire string
        for (char c : s) {
            if (c == '1') total_ones++;
        }
        
        // Pre-parse the ranges of all '0' blocks
        vector<pair<int, int>> zeros;
        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int start = i;
                while (i < n && s[i] == '0') {
                    i++;
                }
                zeros.push_back({start, i - 1});
            } else {
                i++;
            }
        }
        
        int m = zeros.size();
        int n_v = m - 1;
        vector<vector<int>> st;
        
        // Build Sparse Table for O(1) RMQ
        if (n_v > 0) {
            int K = 32 - __builtin_clz(n_v);
            st.assign(K, vector<int>(n_v, 0));
            for (int k = 0; k < n_v; k++) {
                st[0][k] = (zeros[k].second - zeros[k].first + 1) + 
                           (zeros[k+1].second - zeros[k+1].first + 1);
            }
            for (int j = 1; j < K; j++) {
                for (int k = 0; k + (1 << j) <= n_v; k++) {
                    st[j][k] = max(st[j-1][k], st[j-1][k + (1 << (j - 1))]);
                }
            }
        }
        
        auto RMQ = [&](int L, int R) {
            int j = 31 - __builtin_clz(R - L + 1);
            return max(st[j][L], st[j][R - (1 << j) + 1]);
        };
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            
            if (m == 0) {
                ans.push_back(total_ones);
                continue;
            }
            
            // Binary search to find intersecting '0' blocks
            int p = m;
            int low = 0, high = m - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (zeros[mid].second >= l) {
                    p = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            
            int q_idx = -1;
            low = 0, high = m - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (zeros[mid].first <= r) {
                    q_idx = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            
            int gain = 0;
            // Fewer than 2 '0' blocks bounds intersecting within [l, r]
            if (p >= q_idx) {
                gain = 0;
            } else if (q_idx == p + 1) { // Exactly 2 bounded blocks intersecting
                int cp = min(r, zeros[p].second) - max(l, zeros[p].first) + 1;
                int cq = min(r, zeros[q_idx].second) - max(l, zeros[q_idx].first) + 1;
                gain = cp + cq;
            } else { // 3 or more '0' blocks bounded inside limits
                int cp = min(r, zeros[p].second) - max(l, zeros[p].first) + 1;
                int cq = min(r, zeros[q_idx].second) - max(l, zeros[q_idx].first) + 1;
                int len_p_next = zeros[p+1].second - zeros[p+1].first + 1;
                int len_q_prev = zeros[q_idx-1].second - zeros[q_idx-1].first + 1;
                
                // Compare overlaps with inner complete block spans 
                gain = max(cp + len_p_next, len_q_prev + cq);
                
                // Leverage Sparse Table RMQ for spans securely encased within query confines
                if (q_idx - 2 >= p + 1) {
                    gain = max(gain, RMQ(p + 1, q_idx - 2));
                }
            }
            
            ans.push_back(total_ones + gain);
        }
        
        return ans;
    }
};
