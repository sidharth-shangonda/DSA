class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s = "";
        int n=num;
        int i=9;
        while(n--) {
            if(sum >= 9 ) {
                s+=('0'+ 9);
                sum -= 9;
            } else {
                s +=('0' + sum);
                sum -= sum;
            } 
        }
        if(s.size() != num) return "";
        return sum == 0 ? s :"";
    }
};