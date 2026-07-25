class Solution {
public:
    int maxProduct(int n) {
        string s=to_string(n);
        int max1=-1;
        int max2=-1;
        for(auto c:s) {
            int num=c-'0';
            if(num > max1) {
                max2 = max1;
                max1=num;
            } else if(num>max2) {
                max2=num;
            }
        }
        return max1*max2;
    }
};