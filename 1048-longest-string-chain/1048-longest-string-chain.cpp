class Solution {
public:
    bool comp(string a,string b) {
        int j=0;
        int i=0;
        while(i<a.size() && j<b.size()) {
            if(a[i]==b[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        return i==a.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](const string &a,const string &b) {
            return a.length() < b.length(); 
        });
        int n=words.size();
        vector<int> dp(n+1,1);
        int maxlen=1;
        for(int i=1;i<=n;i++) {
            for(int j=i+1;j<=n;j++) {
                int sizei=words[i-1].size();
                int sizej=words[j-1].size();
                if(sizej-sizei>1) break;
                if(sizej-sizei==1 && comp(words[i-1],words[j-1])){
                    dp[j]=max(dp[j],dp[i]+1);
                }
            }
            maxlen=max(maxlen,dp[i]);
        }
        return maxlen;
    }
};