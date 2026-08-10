class Solution {
public:
//this solution will not work because there are not fixed numer of coins sp dp is the best solution
    //here in this solution the value is 1 just click it 
    int coinChange(vector<int>& coins, int amount) {
      //dp approch
      int n=coins.size();
      vector<vector<int>> dp(n+1,vector<int>(amount+1,1e9));
      for(int i=0;i<=n;i++) {
        dp[i][0]=0;
      }
      for(int i=1;i<=n;i++) {
        for(int j=1;j<=amount;j++) {
            if(coins[i-1]<=j) {
                int include=1 + dp[i][j-coins[i-1]];
                int exclude=dp[i-1][j];
                dp[i][j]=min(include,exclude);
            } else {
                dp[i][j]=dp[i-1][j];
            }
        }
      }
      return dp[n][amount]==1e9?-1:dp[n][amount];
    }
};