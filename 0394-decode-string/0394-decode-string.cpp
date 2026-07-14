class Solution {
public:
    string decodeString(string s) {
        stack<int> n;
        stack<string> prevStr;
        string curStr="";
        int num=0;
        for(char c:s) {
            if(isdigit(c)) {
                num=num*10+(c-'0');
            } else if(c == '['){
                n.push(num);
                num=0;
                prevStr.push(curStr);
                curStr="";
            } else if(c == ']') {
                int k=n.top();
                n.pop();
                string prev=prevStr.top();
                prevStr.pop();
                string cur="";
                while(k) {
                    cur+=curStr;
                    k--;
                }
                curStr=prev+cur;
            } else {
                curStr+=c;
            }
        }
        return curStr;
    }
};