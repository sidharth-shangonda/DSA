class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix(n,INT_MIN);
        vector<int> suffix(n,INT_MAX);
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];
        for(int i=1;i<n;i++) {
            prefix[i]=max(prefix[i-1],nums[i]);
            suffix[n-i-1]=min(suffix[n-i],nums[n-i-1]);
        }
        for(int i=0;i<n;i++) {
            if(prefix[i]-suffix[i]<=k) return i;//return index
        }
        return -1;
    }
};