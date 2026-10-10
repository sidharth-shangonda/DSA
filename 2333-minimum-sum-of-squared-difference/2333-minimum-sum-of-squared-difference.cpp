class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> diff;
        long long k=(long long) k1+k2;
        int maxDiff=INT_MIN;
        for(int i=0;i<nums1.size();i++) {
            diff.push_back(abs(nums1[i]-nums2[i]));
            maxDiff=max(maxDiff,abs(nums1[i]-nums2[i]));
        }
        if(maxDiff==0) return 0;
        vector<long long> countd(maxDiff+1,0);
        for(int d:diff) {
            countd[d]++;
        }
        for(int d=maxDiff;d>0;d--) {
            if(countd[d]==0) continue;
            long long take= min(k,countd[d]);
            countd[d]-=take;
            countd[d-1]+=take;
            k-=take;
            if(countd[d]>0) break;//if k == 0 
        }
        long long ans=0;
        for(int d=1;d<=maxDiff;d++) {
            ans+=(countd[d]*d*d*1LL);
        }
        return ans;
    }
};