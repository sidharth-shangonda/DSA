class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++) {
            if(i>0 && nums[i]==nums[i-1]) {
                continue;
            }
            int left=i+1;
            int right=n-1;
            int sum;
            // use correct pointer if sum>0 right -- and <0 left ot mid 
            while(left<right) {
                sum=nums[left] + nums[i] + nums[right];
                if(sum==0) {
                    ans.push_back({nums[i],nums[left],nums[right]});
                    // make sure 0f duplicates
                    while(left<right && nums[left]==nums[left+1]) left++;
                    while(left<right && nums[right]==nums[right-1]) right--;
                    left++;
                    right--;
                } else if(sum>0) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return ans;
    }
};