class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int st=nums[0];
        int end=nums.back();
        vector<int> ans;
        int idx=0;
        for(int i=st;i<=end;i++) {
            if(nums[idx]!=i) {
                ans.push_back(i);
            } else {
                idx++;
            }
        }
        return ans;
    }
};