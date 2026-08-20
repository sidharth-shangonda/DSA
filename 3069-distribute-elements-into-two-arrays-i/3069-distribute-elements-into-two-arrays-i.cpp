class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i=2;i<n;i++) {
            if(arr1.back() > arr2.back()) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }
        int i=0;
        for(int j=0;j<arr1.size();j++) {
            nums[i++]=arr1[j];
        }
        for(int j=0;j<arr2.size();j++) {
            nums[i++]=arr2[j];
        }
        return nums;
    }
};