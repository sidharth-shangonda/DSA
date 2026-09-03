class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minVal=INT_MAX;
        bool isEven=false;
        bool isOdd=false;
        for(int i=0;i<nums1.size();i++) {
            if(nums1[i]%2==0) {
                isEven=true;
            } else {
                isOdd=true;
            }
            minVal=min(minVal,nums1[i]);
        }
        if(minVal%2==0 && isOdd) return false;
        return true;
    }
};