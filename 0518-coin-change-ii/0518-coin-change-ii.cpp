class Solution {
public:
    //change the mening fom the knapsac logic as required 
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<unsigned int>> dp(n+1,vector<unsigned int>(amount+1,0));
        //you have 1 coice if amount=0 i.e select nothing is also a choice 
        for(int i=0;i<=n;i++) {
            dp[i][0]=1;
        }
        //meaning is at i,j the total combination to get sum j with i values.
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=amount;j++) {
                //also we want all combinations include + exclude 
                if(coins[i-1]<=j) {
                    dp[i][j]=dp[i][j-coins[i-1]] + dp[i-1][j];
                } else {
                    dp[i][j]=dp[i-1][j];//dont forget else
                }
            }
        }
        return dp[n][amount];
    }
};