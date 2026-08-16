class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;

        //base case is important and its useful 
        for(int i=1;i<=n;i++) {
            if(p[i-1]!='*') break;
            dp[0][i]=true;
        }
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if(s[i-1]==p[j-1] || p[j-1]=='?') {
                    dp[i][j]=dp[i-1][j-1];
                } else if(p[j-1]=='*') {
                    //either take Match one or more characters 
                    if(dp[i-1][j]==true || dp[i][j-1]==true) dp[i][j]=true;
                } else {
                    dp[i][j]=false;//end of line
                }
            }
        }
        return dp[m][n];
    }
};