class Solution {
public:
    int gcd(int a,int b) {
        if(b==0) return a;
        return gcd(b , a%b);
    }
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        int maxnum=INT_MIN;
        vector<int> prefixGcd(n,0);
        for(int i = 0 ; i < n ; i++ ) {
            maxnum=max(maxnum,nums[i]);
            prefixGcd[i]=gcd(nums[i],maxnum);
        }
        int i=0;
        int j=n-1;
        long long maxSum=0;
        sort(prefixGcd.begin(),prefixGcd.end());
        while(i<j) { // dont use i!=j
            maxSum+=gcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }
        return maxSum;

    }
};