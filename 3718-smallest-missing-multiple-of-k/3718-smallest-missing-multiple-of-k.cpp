class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it:nums) {
            if( k <= it && it%k==0) mp[it]++;
        }
        for(int i=k;;i+=k) {
            if(!mp.count(i)) return i;
        }
        return -1;
    }
};