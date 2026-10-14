class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s = "";
        int n=num;
        while(n--) {
            for(int i=9;i>=0;i--) {
                if(sum >= i) {
                    s+=('0'+ i);
                    sum -= i;
                    break;
                }
            }
        }
        if(s.size() != num) return "";
        return sum == 0 ?s:"";
    }
};