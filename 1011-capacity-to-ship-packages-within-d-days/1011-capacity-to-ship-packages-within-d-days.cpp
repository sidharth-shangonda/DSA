class Solution {
public:
    bool canShip(vector<int>& weights, int days,int weight) {
        int d=0;
        int sum=0;
        for(int i=0;i<weights.size();i++) {
            if(sum + weights[i] > weight) {
                sum=0;
                d++;
            }
            sum+=weights[i];
        }
        if(sum>0) d++;
        return d<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        //no need to sort 
        int low=*max_element(weights.begin(),weights.end());
        long long high=accumulate(weights.begin(),weights.end(),0LL);
        int ans=low-1;
        //for jump 
        while (low <= high) {
            // Find the middle capacity to test
            long long mid = low + (high - low) / 2; 
            
            if (canShip(weights, days, mid)) {
                // If this capacity works, record it as a potential answer
                ans = mid; 
                // But let's see if we can find an even SMALLER capacity that works
                high = mid - 1; 
            } else {
                // If it fails, the capacity is too small. We MUST increase it.
                low = mid + 1; 
            }
        }
        
        return ans;
    }
};