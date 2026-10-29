class Solution {
public:
    bool isInEnd(int idx,string &s, unordered_map<string,int> &mp,vector<int> &dp) {
        if(idx == s.size()) return true;
        if(dp[idx]!=-1) {
            return dp[idx] == 0?false:true;
        }
        string str = "";
        for(int i=idx;i<s.size();i++) {
            str+= s[i];
            if(mp.count(str)) {
                if(isInEnd(i+1,s,mp,dp)) {
                    dp[idx]=1;
                    return true;
                }
            }
        }
        dp[idx]=0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string , int> mp;
        for( auto word: wordDict) {
            mp[word] = 1;
        }
        vector<int> dp(s.size(),-1);
        return isInEnd(0,s,mp,dp);
    }
};