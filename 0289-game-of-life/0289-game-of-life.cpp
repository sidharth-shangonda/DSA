class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size(); 
        vector<pair<int,int>> directions={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
        // vector<vector<bool>> changed(m,vector<bool>(n,false));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                int ones=0;
                for(auto [di,dj]:directions) {
                    int ci=i+di;
                    int cj=j+dj;
                    if(ci>=0 && cj>=0 && ci<m && cj<n) {
                        if((board[ci][cj] & 1)) ones++;
                    }
                }
                // just add the state change to 2nd bit 1 if the current is changing 
                if((board[i][j] & 1) == 1 && (ones==2 || ones==3)) {
                    board[i][j] |=2;
                } else if((board[i][j]& 1) == 0 && ones==3){
                    board[i][j] |=2;//change the 2nd bit 
                }
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                board[i][j] >>= 1;
            }
        }
    }
};