class Solution {
public:
    int isNice(vector<int>& nums, int st,int nw) {
        int n=-1;
        for(int i=st;i<nw;i++) {
            if( (nums[i] & nums[nw]) != 0 )  n=i;
        }
        return n;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int maxSize=1;
        for(int right=1;right<n;right++) {
            if(left==right) continue;
            int x=isNice(nums,left,right);
            if (x!=-1) {
                left=x+1;// exclue the x so add x+1
            }
            maxSize=max(maxSize,right-left+1);//always count the last one 
        }
        return maxSize;
    }
};