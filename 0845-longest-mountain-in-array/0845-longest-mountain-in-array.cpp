class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        if(n<3) return 0;
        vector<int> right(n,1);
        vector<int> left(n,1);
        //left to right
        for(int i=1;i<n;i++) {
            if(arr[i]>arr[i-1]) right[i]=right[i-1]+1;
        }
        //right to left && take max of left and right in right 
        for(int i=n-2;i>=0;i--) {
            if(arr[i]>arr[i+1]) left[i]=left[i+1]+1;
            right[i]=max(right[i],left[i]);
        }
        int maxLen=0;
        for(int i=1;i<n-1;i++) {
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) maxLen=max(maxLen,right[i-1]+right[i+1]+1);
        }
        return maxLen;
    }
};