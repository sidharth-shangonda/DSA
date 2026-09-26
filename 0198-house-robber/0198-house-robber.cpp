class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums.back();
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++) {
            int cur=max(prev2 + nums[i],prev);
            prev2=prev;
            prev=cur;
            
        }
        return prev;
    }
};