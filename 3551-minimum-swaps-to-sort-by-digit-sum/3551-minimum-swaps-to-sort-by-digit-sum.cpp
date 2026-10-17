class Solution {
public:
    class countNums {
    public:
        int sum;
        int num;
        int idx;
    };
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<countNums> digitSum;
        int swaps=0;
        for(int i=0;i<n;i++) {
            int num = nums[i];
            int sum = 0;
            while(num>0) {
                int remd = num % 10;
                sum += remd;
                num /= 10; 
            }
            digitSum.push_back({sum,nums[i],i});
        }
        sort(digitSum.begin(),digitSum.end(),[] (const countNums &a,const countNums &b) {
            if (a.sum == b.sum) {
                return a.num < b.num;
            }
            return a.sum < b.sum;
        });
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++) {
            if(visited[i] || digitSum[i].idx == i) continue;
            int cycleSize = 0;
            int j = i;
            while(!visited[j]) {
                visited[j] = true;
                j = digitSum[j].idx;
                cycleSize++;
            } 
            swaps += cycleSize - 1;
        }
        return swaps;
    }
};