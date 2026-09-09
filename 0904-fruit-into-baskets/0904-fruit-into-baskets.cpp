class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int left=0;
        unordered_map<int,int> mp;
        int ans=0;
        for(int right=0;right<n;right++) {
            mp[fruits[right]]++;
            while(left<n && mp.size()>2) {
                mp[fruits[left]]--;
                if(mp[fruits[left]]==0) mp.erase(fruits[left]);
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};