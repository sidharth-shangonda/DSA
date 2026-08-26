class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.length();
        int left=0;
        int count1s=0;
        string ans="";
        for(int right=0;right<n;right++) {
            if(s[right]=='1') count1s++;
            while(count1s>k) {
                if(s[left]=='1') count1s--;
                left++;
            }
            while(left<=right && s[left]=='0') left++;
            if(k>0 && count1s==k) {
                string temp=s.substr(left,right-left+1);
                if(ans.empty()) ans=temp;
                //comapre the temp and ans 
                else if(temp.size()<ans.size() || (temp.size()==ans.size() && temp<ans)) ans=temp;
            }
        }
        return ans;
    }
};