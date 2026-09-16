long long Mod=1e9 + 7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        long long ans=0;
        vector<int> prev(n,-1);
        vector<int> next(n,n);
        stack<int> s;
        for(int i=0;i<n;i++) {
            while(!s.empty() && arr[s.top()]> arr[i]) {
                s.pop();
            }
            if(!s.empty()) {
                prev[i]=s.top();
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n-1;i>=0;i--) {
            while(!s.empty() && arr[s.top()]>=arr[i]) {
                s.pop();
            }
            if(!s.empty()) {
                next[i]=s.top();
            }
            s.push(i);
        }
        for(int i=0;i<n;i++) {
            ans = (ans + (1LL * arr[i] * (i - prev[i]) * (next[i] - i))%Mod) % Mod;
        }
        return ans;
    }
};