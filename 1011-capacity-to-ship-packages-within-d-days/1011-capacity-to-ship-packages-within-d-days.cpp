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
        long long ans=low-1;
        //for jump 
        long long search_space = high - low + 1;
        long long max_jump = 1;
        while (max_jump <= search_space) {
            max_jump *= 2;
        }
        for(int b=max_jump;b>=1;b/=2) {
            if(ans + b <= high  && !canShip(weights,days,ans+b)) ans+=b;
        }
        return ans+1;
    }
};