class Solution {
    int dp[65][65];
    
    void precomputeDP() {
        for (int i = 0; i < 65; ++i) {
            for (int j = 0; j < 65; ++j) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = 1000; // Treat as infinity
                dp[i][j] = min(dp[i][j], 1 + dp[max(0, i - 1)][j]);             // Digit '2'
                dp[i][j] = min(dp[i][j], 1 + dp[i][max(0, j - 1)]);             // Digit '3'
                dp[i][j] = min(dp[i][j], 1 + dp[max(0, i - 2)][j]);             // Digit '4'
                dp[i][j] = min(dp[i][j], 1 + dp[max(0, i - 1)][max(0, j - 1)]); // Digit '6'
                dp[i][j] = min(dp[i][j], 1 + dp[max(0, i - 3)][j]);             // Digit '8'
                dp[i][j] = min(dp[i][j], 1 + dp[i][max(0, j - 2)]);             // Digit '9'
            }
        }
    }

    int c2[10] = {0, 0, 1, 0, 2, 0, 1, 0, 3, 0};
    int c3[10] = {0, 0, 0, 1, 0, 0, 1, 0, 0, 2};
    int c5[10] = {0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
    int c7[10] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0};

    string buildSuffix(string prefix, int r2, int r3, int r5, int r7, int rem_len) {
        string res = prefix;
        for (int i = 0; i < rem_len; ++i) {
            for (int d = 1; d <= 9; ++d) {
                int nr2 = max(0, r2 - c2[d]);
                int nr3 = max(0, r3 - c3[d]);
                int nr5 = max(0, r5 - c5[d]);
                int nr7 = max(0, r7 - c7[d]);
                
                // If this digit leaves a solvable state in the remaining spots
                if (dp[nr2][nr3] + nr5 + nr7 <= rem_len - 1 - i) {
                    res += to_string(d);
                    r2 = nr2; r3 = nr3; r5 = nr5; r7 = nr7;
                    break;
                }
            }
        }
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        // Step 1: Check prime factors of t
        long long temp = t;
        int req2 = 0, req3 = 0, req5 = 0, req7 = 0;
        while (temp % 2 == 0) { req2++; temp /= 2; }
        while (temp % 3 == 0) { req3++; temp /= 3; }
        while (temp % 5 == 0) { req5++; temp /= 5; }
        while (temp % 7 == 0) { req7++; temp /= 7; }
        
        // If there are primes greater than 7, it's impossible
        if (temp > 1) return "-1"; 
        
        precomputeDP();
        int n = num.length();
        
        vector<int> pref2(n + 1, 0), pref3(n + 1, 0), pref5(n + 1, 0), pref7(n + 1, 0);
        bool has_zero = false;
        int first_zero = -1;
        
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0' && !has_zero) {
                has_zero = true;
                first_zero = i;
            }
            pref2[i + 1] = pref2[i] + c2[num[i] - '0'];
            pref3[i + 1] = pref3[i] + c3[num[i] - '0'];
            pref5[i + 1] = pref5[i] + c5[num[i] - '0'];
            pref7[i + 1] = pref7[i] + c7[num[i] - '0'];
        }
        
        // Step 2: Can the original string be the answer?
        if (!has_zero) {
            if (pref2[n] >= req2 && pref3[n] >= req3 && pref5[n] >= req5 && pref7[n] >= req7) {
                return num;
            }
        }
        
        // Step 3: Find the optimal same-length replacement
        int limit = has_zero ? first_zero : n - 1;
        for (int i = limit; i >= 0; --i) {
            int start_d = num[i] - '0' + 1;
            for (int d = start_d; d <= 9; ++d) {
                int curr2 = pref2[i] + c2[d];
                int curr3 = pref3[i] + c3[d];
                int curr5 = pref5[i] + c5[d];
                int curr7 = pref7[i] + c7[d];
                
                int rem2 = max(0, req2 - curr2);
                int rem3 = max(0, req3 - curr3);
                int rem5 = max(0, req5 - curr5);
                int rem7 = max(0, req7 - curr7);
                
                int rem_len = n - 1 - i;
                
                if (dp[rem2][rem3] + rem5 + rem7 <= rem_len) {
                    return buildSuffix(num.substr(0, i) + to_string(d), rem2, rem3, rem5, rem7, rem_len);
                }
            }
        }
        
        // Step 4: If no same-length configuration exists, expand length
        int required_len = dp[req2][req3] + req5 + req7;
        int L = max(n + 1, required_len);
        
        return buildSuffix("", req2, req3, req5, req7, L);
    }
};
