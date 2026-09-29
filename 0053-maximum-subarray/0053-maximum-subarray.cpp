class Solution {
public:
    int crossSum(vector<int>& nums,int left,int mid,int right) {
        int maxleftSum=INT_MIN;
        int leftSum=0;
        for(int i=mid;i>=left;i--) {
            leftSum+=nums[i];
            maxleftSum=max(maxleftSum,leftSum);
        }
        int maxrightSum=INT_MIN;
        int rightSum=0;
        for(int i=mid+1;i<=right;i++) {
            rightSum+=nums[i];
            maxrightSum=max(maxrightSum,rightSum);
        }
        return maxleftSum+maxrightSum;
    }
    int helper(vector<int>& nums,int left,int right) {
        ///important base case 
        if(left==right) return nums[left];
        int mid=left + (right - left)/2;
        int leftMax=helper(nums,left,mid);
        int rightMax=helper(nums,mid+1,right);
        int crossMax=crossSum(nums,left,mid,right);
        return max({leftMax,rightMax,crossMax});
    }
    int maxSubArray(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};