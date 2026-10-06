class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //extended version of kadans algorithm 
        int maxprd=nums[0];
        int curMax=nums[0];
        int curMin=nums[0];
        for(int i=1;i<nums.size();i++) {
            int num=nums[i];
            if(num<0) {
                swap(curMax,curMin);
            }
            curMax=max(num,curMax*num);
            curMin=min(num,curMin*num);
            maxprd=max(maxprd,curMax);
        }
        return maxprd;
    }
};