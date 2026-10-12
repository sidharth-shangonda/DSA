class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        long long curSum=nums[0];
        int left=0;
        int curRem=nums[0]%k;
        int maxLen=1;
        for(int right=1;right<n;right++) {
            if(nums[right] % k == curRem) {
                curSum+=nums[right];
                if(curSum % k == curRem) maxLen = max(maxLen,right-left + 1);
            } else {
                left=right;
                curSum=nums[right];
                curRem=nums[right]%k;
            }
        }
        if(curSum % k == curRem) maxLen=max(maxLen,n-left);
        return maxLen;
    }
};