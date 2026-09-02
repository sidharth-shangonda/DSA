class Solution {
public:
    bool solve(int div,vector<int>& nums, int threshold) {
        long long sum=0;
        for(int i=0;i<nums.size();i++) {
            sum+=((nums[i]+div)-1)/div;
        }
        if(sum>threshold) return false;
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(),nums.end());
        int low=1;//start from one
        int high=nums.back();
        while(low<high) {
            int mid=low+(high-low)/2;
            if(solve(mid,nums,threshold)) {
                high=mid;
            } else {
                low=mid+1;
            }
        }
        return low;
    }
};