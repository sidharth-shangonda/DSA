class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size(); 
        vector<pair<int,int>> directions={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
        vector<vector<bool>> changed(m,vector<bool>(n,false));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                int ones=0;
                for(auto [di,dj]:directions) {
                    int ci=i+di;
                    int cj=j+dj;
                    if(ci>=0 && cj>=0 && ci<m && cj<n) {
                        if(board[ci][cj]==1) ones++;
                    }
                }
                if(board[i][j]==1) {
                    if(ones<2 || ones>3) changed[i][j]=true;
                } else {
                    if(ones==3) changed[i][j]=true;
                }
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(changed[i][j]) {
                    if(board[i][j]==1) board[i][j]=0;
                    else board[i][j]=1;
                }
            }
        }
    }
};