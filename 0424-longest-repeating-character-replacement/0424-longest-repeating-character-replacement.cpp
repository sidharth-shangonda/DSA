class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        vector<int> freq(26,0);
        int ans=0;
        int maxSim=0;
        int left=0;
        char maxFreq;
        for(int right=0;right<n;right++) {
            freq[s[right]-'A']++;
            if(freq[s[right]-'A']>maxSim) {
                maxSim=freq[s[right]-'A'];
                maxFreq=s[right];
            }
            int curSize=maxSim+k;
            while(left<n && curSize<right-left+1) {
                freq[s[left]-'A']--;
                if(maxFreq==s[left]) maxSim--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
