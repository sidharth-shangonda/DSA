class Solution {
public:
    bool validPalindrome(string s) {
        string cur=s;
        reverse(s.begin(),s.end());
        return s==cur;
    }
    void solve(int idx,string &s,vector<string> &pair,vector<vector<string>> &ans) {
        if(idx==s.size()) {
            ans.push_back(pair);
        }
        string cur="";
        for(int j=idx;j<s.size();j++) {
            cur+=s[j];
            if(validPalindrome(cur)) {
                pair.push_back(cur);
                solve(j+1,s,pair,ans);
                pair.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string &s) {
        vector<vector<string>> ans;
        vector<string> pair;
        solve(0,s,pair,ans);
        return ans;
    }
};