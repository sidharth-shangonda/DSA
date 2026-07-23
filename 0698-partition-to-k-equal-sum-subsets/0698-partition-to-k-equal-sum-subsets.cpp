class Solution {
public:
    bool solve(int idx,vector<int> &sides,vector<int> &nums,int target) {
        if(idx==nums.size()) {
            for(int num:sides) {
                if(num!=target) {
                    return false;
                }
            }
            return true;
        }
        for(int i=0;i<sides.size();i++) {
            if(target<sides[i]+nums[idx]) continue;
            sides[i]+=nums[idx];
            if(solve(idx+1,sides,nums,target)) return true;
            sides[i]-=nums[idx];
            if(sides[i]==0) break;//add break to reduce time complexity
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.rbegin(),nums.rend());
        int n=nums.size();
        long long sum=0;
        int maxNum=0;
        for(int num:nums) {
            sum+=num;
            maxNum=max(num,maxNum);
        }
        if(sum%k!=0 || maxNum > sum/k) return false;
        vector <int> sides(k,0);
        return solve(0,sides,nums,sum/k);
    }
};