class Solution {
public:
    void solve(vector<int> &nums,vector<bool> &present,vector<int> &pair,vector<vector<int>> &ans) {
        if(pair.size()==nums.size()) {
            ans.push_back(pair);
            return;
        }
        for(int i=0;i<nums.size();i++) {
            if(present[i]) continue;
            pair.push_back(nums[i]);
            present[i]=true;
            solve(nums,present,pair,ans);
            pair.pop_back();
            present[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> pair;
        vector<bool> present(n,false);
        solve(nums,present,pair,ans);
        return ans;
    }
};