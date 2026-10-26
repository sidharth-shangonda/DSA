class Solution {
public:
    int calculateSum(pair<int,int>st,vector<vector<bool>> &visited,vector<pair<int,int>>& directions, vector<vector<int>>& grid,int k) {
        long long totalSum = 0;
        int m=grid.size();
        int n=grid[0].size();
        visited[st.first][st.second] = true;
        queue<pair<int,int>> q;
        q.push({st.first,st.second});
        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            totalSum += grid[x][y];
            for(auto [dx,dy]:directions) {
                int cx = dx+x;
                int cy = dy+y;
                if(cx >=0 && cy >= 0 && cx<m && cy<n && !visited[cx][cy] && grid[cx][cy] !=0) {
                    q.push({cx,cy});
                    visited[cx][cy] = true;
                }
            }
        }
        return totalSum % k == 0;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<pair<int,int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int cnt = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(!visited[i][j] && grid[i][j] != 0  && calculateSum({i,j},visited,directions,grid,k)) cnt++;
            }
        }
        return cnt;
    }
};