class Solution {
public:
    long long solve(string &s, int idx,vector<int> &dp) {
        if(s.size()==idx) return 1;
        if(s[idx]=='0') return 0;
        if(dp[idx]!=-1) return dp[idx];
        long long single=0;
        if( (idx+1 == s.size()) || (idx+1<s.size() && s[idx+1]!='0')) {
            single+=solve(s,idx+1,dp);
        }
        long long duo=0;
        if(idx+1 < s.size()) {
            int num=(s[idx]-'0')*10 + (s[idx+1]-'0');
            if(num <= 26 && !(idx+2 < s.size() && s[idx+2]=='0')) {
                duo+=solve(s,idx+2,dp);
            }
        }
        dp[idx]=single+duo;
        return single + duo; 
    }
    int numDecodings(string &s) {
        vector<int> dp(s.size()+1,-1);
        return solve(s,0,dp);
    }
};