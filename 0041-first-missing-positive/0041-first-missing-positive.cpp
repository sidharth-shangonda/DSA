class Solution {
public:
    //for this use cyclic sort
    void swap(int &a,int &b) {
        int temp=a;
        a=b;
        b=temp;
        return;
    }
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++) {
            //use while to prevent all the numbers 
            while(nums[i] >= 1 && nums[i] <= n && nums[nums[i]-1] !=nums[i]) swap(nums[i],nums[nums[i] - 1]);
        }
        for(int i=0;i<n;i++) {
            if(nums[i] != i+1) return i+1;
        }
        return n+1;
    }
};