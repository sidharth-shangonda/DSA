class Solution {
public:
    bool checkDivisibility(int n) {
        long long sd=0;
        long long pd=1;
        long long temp=n*1LL;
        while(temp>0) {
            long long cur=temp%10;
            sd+=cur;
            pd*=cur;
            temp/=10;
        }
        return (n%(sd+pd)==0)?true:false;
    }
};