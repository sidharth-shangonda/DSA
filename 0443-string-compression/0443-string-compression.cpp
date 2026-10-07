class Solution {
public:
    int compress(vector<char>& chars) {
        int len=0;
        int n=chars.size();
        for(int i=0;i<n;i) {
           char cur=chars[i];
            int count=0;
            while(i<n && chars[i]==cur) {
                count++;
                i++;
            }
            chars[len++]=cur;
            if(count>1) {
                string temp=to_string(count);
                for(char c:temp) {
                    chars[len++]=c;
                }
            }
        }
        return len;
    }
};