class Solution {
public:
    // standard two pass type pattern and also the prefix sum pattern 
    vector<int> productExceptSelf(vector<int>& nums) {
        // just use prefix and suffix multiplication for each one 
        int n=nums.size();
        vector<int> ans(n,1);
        int prefix=nums[0];
        for(int i=1;i<n;i++) {
            ans[i]*=prefix;
            prefix*=nums[i];
        }
        int suffix=nums[n-1];
        for(int i=n-2;i>=0;i--) {
            ans[i]*=suffix;
            suffix*=nums[i];
        } 
        return ans;
    }
};