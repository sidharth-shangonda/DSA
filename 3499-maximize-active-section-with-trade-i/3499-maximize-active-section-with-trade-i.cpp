class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int gain = 0;
        vector<pair<int,int>> freqs;
        int i=0;
        char c=s[0];
        int freq=0;
        int ones=0;
        while(i<s.size()) {
            if(s[i]=='1') ones++;
            if(i>0 && s[i]!=s[i-1]) {
                freqs.push_back({c,freq});
                c=s[i];
                freq=0;
            }
            freq++;
            i++;
        }
        freqs.push_back({s[i-1],freq});
        if(freqs.size()>=3) {
            for(int i=2;i<freqs.size();i++) {
                auto left=freqs[i-2];
                auto mid=freqs[i-1];
                auto right=freqs[i];
                if(left.first=='0' && mid.first == '1' && right.first=='0'){
                    gain=max(gain,left.second+right.second);
                }
            }
        }
        return ones+gain;
    }
};