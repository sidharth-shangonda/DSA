class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        long long Sum=0;
        int n=nums.size();
        for(int mask=1;mask < (1 << n) ; mask++) {
            long long XOR=0;
            for(int i=0;i<n;i++) {
                if(mask & (1<<i)) {
                    XOR^=nums[i];
                }
            }
            Sum+=XOR;
        }
        return Sum;
    }
};