class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int j=0;
        int i;
        for(i=1;i<=arr.back();i++) {
            if(i<arr[j]) {
                k--;
            } else {
                j++;
            }
            if(k==0) {
                return i;
            }
        }
        return i+k-1;
    }
};