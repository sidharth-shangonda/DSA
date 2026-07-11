class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
        for(auto c:s) {
            c=tolower(c);
            if((c>='0' && c<='9') || (c>='a' && c<='z')) ans+=c;
        }
        s=ans;
        reverse(s.begin(),s.end());
        return s==ans;
    }
};