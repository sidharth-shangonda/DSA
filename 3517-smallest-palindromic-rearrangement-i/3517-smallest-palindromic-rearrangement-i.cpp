class Solution {
public:
    string smallestPalindrome(string s) {
        sort(s.begin(),s.end());
        vector<int> freqs(26,0);
        for(auto c:s) {
            freqs[c - 'a']++;
        }
        string front="";//back you can reverse
        string extra="";
        for(int i=0;i<26;i++) {
            while(freqs[i]>=2) {
                char c='a' + i;
                front+= c;
                freqs[i]-=2;
            }
            if(freqs[i]>0) extra+= 'a' + i;
        }
        string back=front;
        reverse(back.begin(),back.end());
        return front + extra + back;
    }
};