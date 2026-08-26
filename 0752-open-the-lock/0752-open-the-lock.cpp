class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string,int> mp;
        for(auto s:deadends) {
            mp[s]++;
        }
        if(mp["0000"]) return -1;
        unordered_map<string,int> visited;
        vector<string> directions={"1000","9000","0100","0900","0010","0090","0001","0009"};
        string s="0000";
        visited[s]++;
        int ops=0;
        queue<string> q;
        q.push(s);
        while(!q.empty()) {
            int size=q.size();
            while(size--) {
                string cur=q.front();
                q.pop();
                if(cur==target) return ops;
                for(auto str:directions) {
                    int i=0;
                    string next=cur;
                    while(str[i]=='0') i++;
                    int digit=next[i]-'0';
                    digit=(digit+(str[i]-'0'))%10;
                    next[i]=digit+'0';
                    if(!visited[next] && !mp[next]) {
                        visited[next]++;
                        q.push(next);
                    }
                }
            }
            ops++;
        }
        return -1;
    }
};