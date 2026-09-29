class Solution {
public:
    double xpown(double x,int n) {
        if(n==0) {
            return 1;
        }
        if(n==1) return x;
        double half=xpown(x,n/2);
        if(n%2==0) return half*half;
        return half*half*x;
    }
    double myPow(double x, int n) {
        long long exp=n;
        if(exp<0) {
            x=1.0/x;
            exp= -1* exp;
        }
        return xpown(x,exp);
    }
};