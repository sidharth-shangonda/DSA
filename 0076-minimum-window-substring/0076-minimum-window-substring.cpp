class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        unordered_map<char, int> mp;
        for(auto c:t) {
            mp[c]++;
        }
        int left=0;
        int need=t.size();
        int minLen=INT_MAX;
        int start=0;
        //apply left and right pointer correctly and when you reach the solution then shirnk not before that 
        for(int right=0; right < n ; right++) {
            if(mp[s[right]] > 0) need--;
            mp[s[right]]--;
            while(need==0) {
                if(right-left+1<minLen) {
                    minLen=right-left+1;
                    start=left;
                }
                mp[s[left]]++;
                if(mp[s[left]] > 0) need++;
                left++;
            }
        }
        if(minLen==INT_MAX) return "";
        return s.substr(start,minLen);
    }
};