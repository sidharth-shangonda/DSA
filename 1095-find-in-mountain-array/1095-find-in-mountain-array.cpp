/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peak(MountainArray &mountainArr) {
        int i=0;
        int j=mountainArr.length()-1;
        //by squeez method
        while(i < j) {
            int mid = i + (j - i)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)) {
                i=mid+1;
            } else {
                j=mid;
            }
        }
        return i;
    }
    int searchLeft(MountainArray &mountainArr,int target,int low,int high) {
        while(low<=high) {
            int mid=low + (high - low) / 2;
            if(mountainArr.get(mid)==target) return mid;
            else if(mountainArr.get(mid)>target) high=mid-1;
            else low= mid+1;
        }
        return -1;
    }
    int searchRight(MountainArray &mountainArr,int target,int low,int high) {
        while(low<=high) {
            int mid=low + (high - low) / 2;
            if(mountainArr.get(mid)==target) return mid;
            else if(mountainArr.get(mid)<target) high=mid-1;
            else low= mid+1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int p=peak(mountainArr);
        if(mountainArr.get(p)==target) return p;
        int left=searchLeft(mountainArr,target,0,p-1);
        if(left!=-1) return left;
        int right=searchRight(mountainArr,target,p+1,n-1);
        return right;
    }
};