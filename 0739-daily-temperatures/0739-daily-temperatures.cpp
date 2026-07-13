class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack <int> s;
        vector <int> ans(n,0);
        for(int i=n-1;i>=0;i--) {
            int num=temperatures[i];
            if(s.empty()) {
                s.push(i);
                continue;
            }
            while(!s.empty() && num>=temperatures[s.top()]) s.pop();//dont forget duplicates 
            if(!s.empty()) ans[i]=s.top()-i;
            s.push(i);
        }
        return ans;
    }
};