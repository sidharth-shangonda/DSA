class Solution {
public:
    int minOperations(string s) {
        //base case
        int n = s.size();
        if( n <=1 ) return 0;
        if( n == 2) {
            if( s[0] > s[1]) return -1;
            return 0;
        }
        string temp1 = s;
        string temp2 = s;
        sort(s.begin(),s.end());
        if(temp1 == s) return 0;//base case
        int ops = 0;
        sort(temp1.begin(),temp1.begin() + n -1);
        sort(temp2.begin()+ 1, temp2.end());
        ops++;
        if(temp1 == s || temp2 == s) return ops;
        sort(temp1.begin()+ 1, temp1.end());
        sort(temp2.begin(),temp2.begin() + n -1);
        ops++;
        if(temp1 == s || temp2 == s) return ops;
        sort(temp2.begin(),temp2.begin() + n -1);
        sort(temp2.begin()+ 1, temp2.end());
        ops++;
        if(temp1 == s || temp2 == s) return ops;
        return -1;
    }
};