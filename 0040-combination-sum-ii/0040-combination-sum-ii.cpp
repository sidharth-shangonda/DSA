class Solution {
public:
    void allPairs(int idx,int target,vector<int> &candidates,vector<int> &pairs,vector<bool> &visited,vector<vector<int>> &ans) {
        if(target == 0) {
            ans.push_back(pairs);
            return;
        }
        for(int i=idx;i<candidates.size();i++) {
            if(i>0 && candidates[i]==candidates[i-1] && !visited[i-1]) continue;
            if(target>=candidates[i]) {
                visited[i]=true;
                pairs.push_back(candidates[i]);
                allPairs(i+1,target-candidates[i],candidates,pairs,visited,ans);
                pairs.pop_back();
                visited[i]=false;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> pairs;
        vector<vector<int>> ans;
        vector<bool> visited(candidates.size(),false);
        allPairs(0,target,candidates,pairs,visited,ans);
        return ans;
    }
};