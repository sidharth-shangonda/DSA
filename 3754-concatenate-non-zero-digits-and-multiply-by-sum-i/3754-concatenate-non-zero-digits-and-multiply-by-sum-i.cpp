class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long num=0;
        while(n>0) {
            long long rem=n%10;
            if(rem==0) {
                n/=10;
                continue;
            }
            num=num*10+rem;
            sum+=rem;
            n/=10;
        }
        while(num>0) {
            long long rem=num%10;
            n=n*10+rem;
            num/=10;
        }
        return n*sum;
    }
};