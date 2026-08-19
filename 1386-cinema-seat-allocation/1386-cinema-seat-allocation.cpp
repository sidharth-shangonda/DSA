class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<pair<int,int>,int> mp;//use map because unordrered map doesnt provide pair hash value
        set<int> s;
        for(auto &e:reservedSeats) {
            mp[{e[0],e[1]}]++;
            s.insert(e[0]);
        }
        int ans=(n-s.size())*2;
        for(auto i:s) {
            bool seats1=true;
            bool seats2=true;
            bool seats3=true;
            for(int j=2;j<=5;j++) {
                if(mp.count({i,j})) {
                    seats1=false;
                    break;
                }
            }
            for(int j=4;j<=7;j++) {
                if(mp.count({i,j})) {
                    seats2=false;
                    break;
                }
            }
            for(int j=6;j<=9;j++) {
                if(mp.count({i,j})) {
                    seats3=false;
                    break;
                }
            }
            if(seats1 && seats3) {
                ans+=2;
            } else if(seats1 || seats2 || seats3){
                ans++;
            } 
        }
        return ans;
    }
};