class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int digit1=to_string(low).length();
        int digit2=to_string(high).length();
        vector<int> ans;
        for(int d=digit1;d<=digit2;d++) {
            int ones=0;
            for(int i=0;i<d;i++) ones=ones*10+1;
            int num=0;
            for(int i=1;i<=d;i++) num= num*10+i;
            while(num<=high) {
                if(num>=low) ans.push_back(num);
                if(num%10==9) break;
                num+=ones;
            }
        }
        return ans;
    }
};