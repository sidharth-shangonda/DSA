class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> s;
        for(auto ch:tokens) {
            if(ch == "+") {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                int c=b+a;
                s.push(c);
            } else if(ch == "-") {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                int c=b-a;
                s.push(c);
            } else if(ch == "*") {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                int c=b*a;
                s.push(c);
            } else if(ch == "/") {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                int c=b/a;
                s.push(c);
            } else {
                s.push(stoi(ch));
            }
        }
        return s.top();
    }
};