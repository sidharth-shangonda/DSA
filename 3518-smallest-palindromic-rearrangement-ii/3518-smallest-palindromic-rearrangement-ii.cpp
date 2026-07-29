class Solution {
public:
    long long comb(int n, int r, long long limit) {
        if (r > n) return 0;
        r = min(r, n - r);

        long long ans = 1;

        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans > limit) return limit;
        }

        return ans;
    }

    long long countWays(vector<int>& freqs, long long limit) {
        int total = 0;
        for (int x : freqs)
            total += x;

        long long ans = 1;

        for (int x : freqs) {
            if (x == 0) continue;

            ans *= comb(total, x, limit);

            if (ans > limit)
                return limit;

            total -= x;
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {

        sort(s.begin(), s.end());

        int n = s.size() / 2;

        vector<int> freqs(26, 0);

        string extra = "";

        for (char c : s)
            freqs[c - 'a']++;

        for (int i = 0; i < 26; i++) {
            if (freqs[i] % 2)
                extra = char('a' + i);

            freqs[i] /= 2;
        }

        if (countWays(freqs, k) < k)
            return "";

        string ans = "";

        int place = 0;

        while (place < n) {

            for (int i = 0; i < 26; i++) {

                if (freqs[i] == 0)
                    continue;

                freqs[i]--;

                long long ways = countWays(freqs, k);

                if (ways >= k) {

                    ans += char('a' + i);
                    place++;
                    break;
                }

                k -= ways;
                freqs[i]++;
            }
        }

        string back = ans;
        reverse(back.begin(), back.end());

        return ans + extra + back;
    }
};