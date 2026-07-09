class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        long long sum=0;
        int ans=0;
        unordered_map<int,int> mp;
        mp[0]=1;//for sum =0
        for(int num:nums) {
            sum+=num;
            if(mp.count(sum-k)) ans+=mp[sum-k];//count properly the sum may be repeated
            mp[sum]++;
        }
        return ans;
    }
};