class Solution {
public:
    void solve(int i,int n,int k,vector<vector<int>> &ans,vector<int> &pair) {
        if(pair.size()==k) {
            ans.push_back(pair);
            return;
        }
        if(i>n) return;
        pair.push_back(i);
        solve(i+1,n,k,ans,pair);
        pair.pop_back();
        //skip
        solve(i+1,n,k,ans,pair);

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> pair;
        solve(1,n,k,ans,pair);
        return ans;
    }
};