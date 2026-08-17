class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> dp(n+1,1);
        int maxLen=1;
        int idx=0;
        for(int i=1;i<=n;i++) {
            for(int j=i+1;j<=n;j++) {
                if(nums[j-1]%nums[i-1]==0) {
                    dp[j]=max(dp[j],dp[i]+1);
                }
            }
            if(maxLen<dp[i]) {
                maxLen=dp[i];
                idx=i-1;
            }
        }
        cout << maxLen << " " << idx <<endl;
        vector<int> ans(maxLen);
        // while back tracing we use dp array
        if(maxLen>1) {
            int j=maxLen-1;
            ans[j]=nums[idx];
            j-=1;
            maxLen-=1;
            for(int i=idx-1;i>=0 && j>=0;i--) {
                if(dp[i+1]==maxLen && ans[j+1] % nums[i]==0 ) {// here to compare the dp array also the divide back array
                    ans[j]=nums[i];
                    maxLen--;
                    j--;
                }
            }
        } else {
            return {nums.back()};
        }
        return ans;
    }
};