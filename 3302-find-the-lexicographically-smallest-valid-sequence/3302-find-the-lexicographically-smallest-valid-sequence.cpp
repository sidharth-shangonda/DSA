class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int> dp(n+1,0);
        int j=m-1;
        for(int i=n-1;i>=0;i--) {
            if(j>=0 && word1[i]==word2[j]) {
                j--;
                dp[i]=dp[i+1]+1;
            } else {
                dp[i]=dp[i+1];
            }
        }
        j=0;
        bool checked=false;
        vector<int> ans;
        for(int i=0;i<n && j<m;i++) {
            if( word1[i]==word2[j]) {
                ans.push_back(i);
                j++;
            } else if(!checked && dp[i+1] >= m-j-1) {//it should be dp[i+1]
                checked=true;
                ans.push_back(i);
                j++;
            }
        }
        if(j==m) return ans;
        return {};
    }
};