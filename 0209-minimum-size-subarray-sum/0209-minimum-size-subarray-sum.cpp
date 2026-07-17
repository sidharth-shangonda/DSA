class Solution {
public:
    bool isValid(int target, vector<int>& nums,int length) {
        int left=0;
        long long sum=0;
        for(int right=0;right<nums.size();right++) {
            sum+=nums[right];
            if(right - left + 1 > length ) {
                sum-=nums[left];
                left++;
            }
            if(right-left+1 == length && sum >= target) return true;
        }
        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        long long sum=accumulate(nums.begin(),nums.end(),0);
        if(target > sum) return 0;
        int low=1;
        int high=n;
        while(low<high) {
            int mid=low + (high - low) / 2;
            if(isValid(target,nums,mid)) {
                high=mid;
            } else {
                low=mid+1;
            }
        }
        return low;
    }
};