class Solution {
public:
    int minimumPushes(string word) {
        long long ans=0;
        unordered_map<char, int> mp;
        for(auto ch:word) {
            mp[ch]++;
        }
        priority_queue<pair<int , char>> pq;
        for(auto it:mp) {
            pq.push({it.second,it.first});
        }
        int i=1;
        while(!pq.empty()) {
            auto it=pq.top();
            pq.pop();
            int freq=it.first;
            if(i<=8) {
                ans+=1*freq;
            } else if(i<=16) {
                ans+=2*freq;
            } else if(i<=24){
                ans+=3*freq;
            } else {
                ans+=4*freq;
            }
            i++;
        }
        return ans;
    }
};