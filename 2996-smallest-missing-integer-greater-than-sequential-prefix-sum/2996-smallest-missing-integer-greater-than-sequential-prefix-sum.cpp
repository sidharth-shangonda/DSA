class Solution {
public:
    int missingInteger(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        long long sum=nums[0];
        mp[nums[0]]++;
        bool isTrue=true;
        for(int i=1;i<nums.size();i++) {
            if(nums[i]==nums[i-1]+1 && isTrue) {
                sum+=nums[i];
            } else {
                isTrue=false;
            }
            mp[nums[i]]++;
        }
        //if all are in increasing
        while(mp.count(sum)) sum++;
        return sum;
    }
};