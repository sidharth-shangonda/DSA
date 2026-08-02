class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<pair<int,int>> directions={{-1, 0},{0,1},{1,0},{0,-1}};
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++) {
            if(board[i][0] == 'O') {
                q.push({i,0});
                visited[i][0]=true;
            }
        }
        for(int i=0;i<m;i++) {
            if(board[i][n-1] == 'O') {
                q.push({i,n-1});
                visited[i][n-1]=true;
            }
        }
        for(int i=0;i<n;i++) {
            if(board[0][i] == 'O') {
                q.push({0,i});
                visited[0][i]=true;
            }
        }
        for(int i=0;i<n;i++) {
            if(board[m-1][i] == 'O') {
                q.push({m-1,i});
                visited[m-1][i]=true;
            }
        }
        while(!q.empty()) {
            int size=q.size();
            while(size--) {
                auto [x,y]=q.front();
                q.pop();
                for(auto [dx,dy]:directions) {
                    int cx=dx+x;
                    int cy=dy+y;
                    if(cx>=0 && cy>=0 && cx<m && cy<n && !visited[cx][cy] && board[cx][cy] == 'O') {
                        visited[cx][cy]=true;
                        q.push({cx,cy});
                    }
                }
            }
        }
        for(int i=1;i<m-1;i++) {
            for(int j=1;j<n-1;j++) {
                if( !visited[i][j] && board[i][j] == 'O') board[i][j]='X';
            }
        }
    }
};