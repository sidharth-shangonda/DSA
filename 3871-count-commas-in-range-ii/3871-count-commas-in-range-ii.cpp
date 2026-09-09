class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        ans += max(0LL, n - 999LL);
        ans += max(0LL, n - 999999LL);
        ans += max(0LL, n - 999999999LL);
        ans += max(0LL, n - 999999999999LL);
        ans += max(0LL, n - 999999999999999LL);
        return ans;
    }
};