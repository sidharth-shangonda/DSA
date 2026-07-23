class Solution {
public:
    bool solve(int i,vector<int> &sticks,vector<int> &sides,int target) {
        if(i == sticks.size()) {
            return sides[0]==target && sides[1]==target && sides[2]==target && sides[3]==target;
        }
         
        for(int x=0;x<4;x++) {
            if(target<sticks[i] + sides[x]) continue;
            sides[x]+=sticks[i];
            if(solve(i+1,sticks,sides,target)) return true;//check for the next one willit fit then true else false ot repeat the loop
            sides[x]-=sticks[i];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.rbegin(), matchsticks.rend());//sort decendinglhy
        int n=matchsticks.size();
        long long perimeter=0;
        long long maxLen=0;
        for(int num: matchsticks) {
            perimeter+=num;
            maxLen=max(maxLen,1LL*num);
        }
        if(perimeter%4!=0 || maxLen > perimeter/4 || n<4) return false;
        vector<int> sides(4,0);
        return solve(0,matchsticks,sides,perimeter/4);
    }
};