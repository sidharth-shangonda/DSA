class Solution {
public:
    long long gcdOfArray(vector<int> &numsDivide) {
        long long g=0;
        for(int num:numsDivide) {
            g=gcd(g,num);
        }
        return g;
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(),nums.end());
        long long g = gcdOfArray(numsDivide);
        int i=0;
        while(i<nums.size() && nums[i] <= g) {
            if(g % nums[i] == 0) return i;
            i++;
        }
        return -1;
    }
};