class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack <int> s;
        for(int num:asteroids) {
            if(num>0) {
                s.push(num);
            } else {
                while(!s.empty() && num<0 && s.top()>0){
                    int top=s.top();
                    int tnum=abs(num);
                    if(tnum>top) {
                        s.pop();
                    } else if(tnum==top) {
                        s.pop();
                        num=0;
                        break;
                    } else {
                        num=0;
                        break;
                    }
                }
                if(num!=0) {
                    s.push(num);
                }
            }
        }
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};