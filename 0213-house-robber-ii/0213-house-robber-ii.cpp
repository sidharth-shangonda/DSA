class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return max(nums[0],nums.back());
        vector<int> dp1(n-1,0);
        vector<int> dp2(n-1,0);
        for(int i=0;i<n-1;i++) {
            dp1[i]=max(dp1[i],nums[i]);
            if(i-2>=0) dp1[i]=max(dp1[i],nums[i]+dp1[i-2]);
            if(i-3>=0) dp1[i]=max(dp1[i],nums[i]+dp1[i-3]);
        }
        for(int i=0;i<n-1;i++) {
            dp2[i]=max(dp2[i],nums[i+1]);
            if(i-2>=0) dp2[i]=max(dp2[i],nums[i+1]+dp2[i-2]);
            if(i-3>=0) dp2[i]=max(dp2[i],nums[i+1]+dp2[i-3]);
        }
        return max(max(dp1[n-2],dp1[n-3]),max(dp2[n-2],dp2[n-3]));
    }
};