class Solution {
public:
    bool solve(int days,int m,int k,vector<int>& bloomDay) {
        int n=bloomDay.size();
        vector<bool> plucked(n,false);
        int bqts=0;
        for(int i=0;i<n;i++) {
            if(!plucked[i] && bloomDay[i]<=days) {
                //now check for the adjecent flowers
                int cnt=0;
                int j=i;
                while(j<n && bloomDay[j]<=days && cnt<k) {
                    cnt++;
                    plucked[j]=true;
                    j++;
                }
                if(cnt==k) {
                    bqts++;
                }
            }
        }
        return bqts>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(n*1LL <  1LL* m*k) return -1;
        int low=1;
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        while(low<high) {
            int mid=low + (high - low)/2;
            if(solve(mid,m,k,bloomDay)) {
                high=mid;
            } else {
                low=mid+1;
            }
        }
        return low;
    }
};