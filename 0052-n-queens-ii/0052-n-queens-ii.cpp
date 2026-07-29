class Solution {
public:
void storeBoard(vector<vector<char>> &board,vector<vector<string>> &ans) {
        string str="";
        vector<string> board1;
        for(int i=0;i<board.size();i++) {
            str="";
            for(int j=0;j<board.size();j++) {
                str+=board[i][j];
            }
            board1.push_back(str);
        }
        ans.push_back(board1);
    }
    bool isSafe(vector<vector<char>> &board,int row,int col) {
    // //check columns(horizontal)
    // for(int j=0;j<board.size();j++) {
    //     if(board[row][j]=='Q') {
    //         return false;
    //     }
    // }

    //check rows(vertical)
    for(int i=0;i<=row;i++) {
        if(board[i][col]=='Q') {
            return false;
        }
    }
    // check upper left diagonal
    for(int i=row,j=col;i>=0 && j>=0;i--,j--) {
        if(row>=0 && col>=0 && board[i][j]=='Q') {
            return false;
        }
    }
    //check upper right diagonals
    for(int i=row,j=col;i>=0 && j<board[0].size();i--,j++){
        if(i>=0 && j<board[0].size() && board[i][j]=='Q') {
            return false;
        }
    }
    return true;
    }

    void nQueen(vector<vector<char>> &board,int row,vector<vector<string>> &ans) {
        if(row==board.size()) {
            storeBoard(board,ans);
            cout<< endl;
            return;
        }
        for(int j=0;j<board.size();j++) {
            if(isSafe(board,row,j)) {
                board[row][j]='Q';
                nQueen(board,row+1,ans);
                board[row][j]='.';//backtrack
            }
        }
    }
    int totalNQueens(int n) {
         vector<vector<char>> board(n,vector<char>(n,'.'));
        vector<vector<string>> ans;
        nQueen(board,0,ans);
        return ans.size();
    }
};