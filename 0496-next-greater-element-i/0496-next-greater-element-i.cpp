class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        stack<int> s;
        vector<int> ans(n,-1);
        unordered_map<int,int> mp;
        for(int i=n-1;i>=0;i--) {
            while(!s.empty() && s.top()<nums2[i]) {
                s.pop();
            }
            if(!s.empty()) {
                ans[i]=s.top();
            }
            s.push(nums2[i]);
            mp[nums2[i]]=ans[i];
        }
        vector<int> result(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++) {
            if(mp.count(nums1[i])) {
                result[i]=mp[nums1[i]];
            }
        }
        return result;
    }
};