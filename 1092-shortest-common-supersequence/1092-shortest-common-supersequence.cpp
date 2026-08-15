class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int m=s.size();
        int n=t.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if(s[i-1]==t[j-1]) {
                    dp[i][j]=1+dp[i-1][j-1];
                } else {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        // npw we backtrack through the solution so it will be so we can fidn the exact sequesnce 
        // main idea is if we backtrack from dp[m][n] to the final points by adding some strings so it willbe easy
        string ans="";
        int i=m,j=n;
        while(i>0 && j>0) {
            //if the string matches so go to i-1,j-1 
            if(s[i-1]==t[j-1]) {
                ans+=s[i-1];
                i--;
                j--;
            } else {
                //just add the string that is not in the subsequene and move to the best side 
                if(dp[i][j-1]>dp[i-1][j]) {
                    ans+=t[j-1];
                    j--;
                } else {
                    ans+=s[i-1];
                    i--;
                }
            }
        }
        while(i>0){
            ans+=s[i-1];
            i--;
        }
        while(j>0) {
            ans+=t[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};