class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int length=0;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='('){
                if(length>0){
                    ans+=s[i];
                }
                length++;
            }else{
                length--;
                if(length>0) {
                    ans+=s[i];
                }
            }
        }
        return ans;

    }
};