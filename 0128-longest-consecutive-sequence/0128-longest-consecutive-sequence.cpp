class Solution {
public:
    // just check the prevoous value exists 
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp(nums.begin(),nums.end());//just to see weather the number exists 
        int maxCount=0;
        for(auto num:mp) { //removes counting of duplicates 
            int count=0;
            if(!mp.count(num-1)) {
                count =1;
                while(mp.count(num+1)) {
                    count++;
                    num++;
                }
            }
            maxCount=max(maxCount,count);
        }
        return maxCount;
    }
};