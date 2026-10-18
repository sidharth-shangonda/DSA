class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = tickets[k];
        int n = tickets.size();
        int i = k-1;
        int j = k+1;  
        while(i >= 0) {
            if(tickets[i] > tickets[k]) {
                ans += tickets[k];
            } else {
                ans += tickets[i];
            }
            i--;
        }
        while(j < n) {
            if(tickets[j] >= tickets[k]) {
                ans += tickets[k] - 1;
            } else {
                ans += tickets[j];
            }
            j++;
        }
        return ans;
    }
};