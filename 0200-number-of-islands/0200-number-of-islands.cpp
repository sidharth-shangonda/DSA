class Solution {
public:
    void bfs(vector<vector<char>>& board,vector<vector<bool>> &visited,pair<int,int> st) {
        int m=board.size();
        int n=board[0].size();
        vector<pair<int,int>> directions={{-1, 0},{0,1},{1,0},{0,-1}};
        queue<pair<int,int>> q;
        q.push({st.first,st.second});
        visited[st.first][st.second]=true;
        while(!q.empty()) {
            auto [x,y]=q.front();
            q.pop();
            for(auto [dx,dy]:directions) {
                int cx=dx+x;
                int cy=dy+y;
                if(cx>=0 && cy>=0 && cx<m && cy<n && !visited[cx][cy] && board[cx][cy] == '1') {
                    visited[cx][cy]=true;
                    q.push({cx,cy});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<pair<int,int>> directions={{-1, 0},{0,1},{1,0},{0,-1}};
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<pair<int,int>> q;
        int islands=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j] == '1' && !visited[i][j] ) {
                    bfs(board,visited,{i,j});
                    islands++;
                }
            }
        }
        return islands;
    }
};