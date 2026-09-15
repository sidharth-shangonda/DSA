class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       int n=nums.size();
       stack<int> s;
       vector<int> ans(n,-1);
       for(int i=2*n-1;i>=0;i--) {
        while(!s.empty() && nums[s.top()%n] <= nums[i%n] ) {
            s.pop();
        }
        if(s.empty()) {
            s.push(i%n);
            continue;
        }
        ans[i%n]=nums[s.top()%n];
        s.push(i%n);
       }
       return ans;
    }
};