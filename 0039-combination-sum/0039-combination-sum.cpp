class Solution {
public:
    void combinations(int idx, int target,vector<int> &candidates,vector<int> &pairs,vector<vector<int>> &ans) {
        if(target == 0 ) {
            ans.push_back(pairs);
            return;
        }
        if(idx>=candidates.size()) return;
        if(candidates[idx]<=target) {
            pairs.push_back(candidates[idx]);
            combinations(idx,target-candidates[idx],candidates,pairs,ans);
            pairs.pop_back();
        }
        combinations(idx+1,target,candidates,pairs,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> pairs;
        vector<vector<int>> ans;
        combinations(0,target,candidates,pairs,ans);
        return ans;
    }
};