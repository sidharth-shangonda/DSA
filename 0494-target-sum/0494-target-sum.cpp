class Solution {
public:
    int findSum(int n,long long curSum,long long sum,int target,vector<int>& nums,vector<vector<int>> &dp) {
        if(n==0) {
            if(curSum==target) return 1;//combination found
            return 0;
        }
        if(dp[n][curSum+sum]!=-1) {
            return dp[n][curSum+sum];
        }
        //we want total combinatios of add and sub
        int add=findSum(n-1,curSum+nums[n-1]*1LL,sum,target,nums,dp);
        int sub=findSum(n-1,curSum-nums[n-1]*1LL,sum,target,nums,dp);
        return dp[n][curSum+sum]=add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        long long sum=accumulate(nums.begin(),nums.end(),0);
        if(abs(target)>sum) return 0;
        vector<vector<int>> dp(n+1,vector<int>(2*sum+1,-1));
        if(target<0) target*=-1;

        return findSum(n,0,sum,target,nums,dp);
    }
};