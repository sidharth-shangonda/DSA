class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> st;
        unordered_map<char,int> mp;
        for(auto c:s) {
            mp[c]++;
        }
        unordered_set<char> inStack;
        int size=mp.size();
        
        for(auto c:s) {
            mp[c]--;
            if(inStack.count(c)) {
                continue;
            }
            while(!st.empty() && mp[st.top()] > 0 &&  st.top()>c && !inStack.count(c)) {
                inStack.erase(st.top());
                st.pop();
            }
            
            st.push(c);
            inStack.insert(c);
        }
        string ans="";
        while(!st.empty()) {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};