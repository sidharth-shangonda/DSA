class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return max(nums[0],nums.back());
        vector<int> dp(n,0);
        for(int i=0;i<n;i++) {
            dp[i]=max(dp[i],nums[i]);
            if(i-2>=0) dp[i]=max(dp[i],nums[i]+dp[i-2]);
            if(i-3>=0) dp[i]=max(dp[i],nums[i]+dp[i-3]);
        }
        return max(dp[n-2],dp[n-1]);
    }
};