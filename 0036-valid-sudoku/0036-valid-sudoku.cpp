class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> rows(9);
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j]=='.') continue;
                if(!rows[i].count(board[i][j]-'0')) rows[i].insert(board[i][j]-'0');
                else return false;
            }
        }
        vector<set<int>> column(9);
        for(int j=0;j<9;j++) {
            for(int i=0;i<9;i++) {
                if(board[i][j]=='.') continue;
                if(!column[j].count(board[i][j]-'0')) column[j].insert(board[i][j]-'0');
                else return false;
            }
        }
        for(int i=3;i<=9;i+=3) {
            for(int j=3;j<=9;j+=3) {
                set<int> box;
                for(int x=i-3;x<i;x++) {
                    for(int y=j-3;y<j;y++) {
                        if(board[x][y]=='.') continue;
                        if(!box.count(board[x][y]-'0')) box.insert(board[x][y]-'0');
                        else return false;
                    }
                }
            }
        }
        return true;
    }
};