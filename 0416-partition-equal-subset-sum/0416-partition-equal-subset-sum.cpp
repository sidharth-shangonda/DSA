class Solution {
public:
    bool tabulation(int targetSum,vector<int> &arr) {
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(targetSum+1,0));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=targetSum;j++) {
                if(arr[i-1]<=j) {
                    int include = arr[i-1] + dp[i-1][j-arr[i-1]];
                    int exclude = dp[i-1][j];
                    dp[i][j] = max(include,exclude);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][targetSum]==targetSum;
    }
    bool canPartition(vector<int>& nums) {
        long long sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1) return false;
        int target=(int) sum/2;
        return tabulation(target,nums);
    }
};