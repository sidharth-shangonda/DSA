class Solution {
public:
    int countPairs(vector<int> &nums,int low,int mid,int high) {
        int inv=0;
        int right=mid+1;
        for(int left=low;left<=mid;left++) {
            while( right <= high &&  ((long long) nums[left] > 1LL * 2 *nums[right]) ) {
                right++;
            }
            inv += right - (mid+1);
        }
        return inv;
    }
    void merge(vector <int> &nums,int low,int mid,int high) {
        int i=low;
        int j=mid+1;
        int k=0;
        vector<int> temp(high-low+1);
        while(i<=mid && j<=high) {
            if(nums[i]>nums[j]) {
                temp[k++]=nums[j++]; 
            } else {
                temp[k++]=nums[i++];
            }
        }
        while(i<=mid) temp[k++]=nums[i++];
        while(j<=high) temp[k++]=nums[j++];
        for(int left=high;left>=low;left--) {
            nums[left]=temp[k-1];
            k--;
        }
    }
    int mergeSort(vector <int> &nums,int low,int high) {
        if(low >= high) return 0;
        int mid = low + (high - low)/2;
        int inv=mergeSort(nums,low,mid);
        inv += mergeSort(nums,mid+1,high);
        inv+=countPairs(nums,low,mid,high);
        merge(nums,low,mid,high);
        return inv;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};