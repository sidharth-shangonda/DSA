class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        set<int> s;
        for(auto candy:candyType) {
            s.insert(candy);
        }
        int m=s.size();
        return (m<=n/2) ? m : n/2;
    }
};