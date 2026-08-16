using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int counts[3] = {0, 0, 0};
        
        // Count frequencies of remainders
        for (int stone : stones) {
            counts[stone % 3]++;
        }
        
        // Even number of 0s
        if (counts[0] % 2 == 0) {
            return counts[1] > 0 && counts[2] > 0;
        }
        
        // Odd number of 0s
        return abs(counts[1] - counts[2]) > 2;
    }
};
