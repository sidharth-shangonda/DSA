class Solution {
public:  
    void solve(int idx,string s,vector<vector<string>> &ans,vector<string> &pair) {
        string temp="";
        if(!pair.empty()) {
            temp=pair.back();
            reverse(temp.begin(),temp.end());
        }
        if(idx==s.size()){
            if(temp == pair.back()) {
                ans.push_back(pair);
            }
            return;
        }
        if(pair.empty() || temp==pair.back()) {
            string t{s[idx]};
            pair.push_back(t);
            solve(idx+1,s,ans,pair);
            pair.pop_back();
        }
        if(!pair.empty()) {
            string t=pair.back();
            pair.pop_back();
            pair.push_back(t+s[idx]);
            solve(idx+1,s,ans,pair);
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> pair;
        solve(0,s,ans,pair);
        return ans;
    }
};