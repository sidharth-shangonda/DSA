class Solution {
public:
    
    int findTargetSumWays(vector<int>& coins, int target) {
        int n=coins.size();
        int sum=accumulate(coins.begin(),coins.end(),0);
        int amount=(sum+target)/2;
        if(abs(target)>sum || (sum + target) % 2 != 0) return 0;
        vector<vector<unsigned int>> dp(n+1,vector<unsigned int>(amount+1,0));
        //you have 1 coice if amount=0 i.e select nothing is also a choice 
        dp[0][0]=1;
        //meaning is at i,j the total combination to get sum j with i values.
        for(int i=1;i<=n;i++) {
            for(int j=0;j<=amount;j++) {
                //also we want all combinations include + exclude 
                if(coins[i-1]<=j) {
                    dp[i][j]=dp[i-1][j-coins[i-1]] + dp[i-1][j];
                } else {
                    dp[i][j]=dp[i-1][j];//dont forget else
                }
            }
        }
        return dp[n][amount];
    }
};