class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int lb = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int up = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
        if(lb == n) return {};
        vector<int> ans;
        for(int i=lb; i<up; i++) {
            ans.push_back(i);
        }
        return ans;
    }
};