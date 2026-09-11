class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        vector<int> freq(10,0);
        int ans=0;
        for(int i=0;i<n;i++) {
            freq[digits[i]]++;
        }
        for(int h=1;h<=9;h++) {
            if(freq[h]==0) continue;
            freq[h]--;
            for(int t=0;t<=9;t++) {
                if(freq[t]==0) continue;
                freq[t]--;
                for(int u=0;u<=8;u+=2) {
                    if(freq[u]==0) continue;
                    ans++;
                }
                freq[t]++;
            }
            freq[h]++;
        }
        return ans;
    }
};