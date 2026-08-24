class Solution {
public:
    int area(pair<int,int> st,vector<vector<bool>> &visited,vector<pair<int,int>> &directions,vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int a=0;
        queue<pair<int,int>> q;
        q.push({st.first,st.second});
        visited[st.first][st.second] =true;
        while(!q.empty()) {
            auto [x,y]=q.front();
            q.pop();
            a++;
            for(auto [dx,dy]:directions) {
                int cx=dx+x;
                int cy=dy+y;
                if(cx>=0 && cy>=0 && cx<m && cy<n && !visited[cx][cy] && grid[cx][cy]==1) {
                    visited[cx][cy]=true;
                    q.push({cx,cy});
                }
            }
        }
        return a;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        vector<pair<int,int>> directions={{-1,0},{0,1},{1,0},{0,-1}};
        int maxArea=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(!visited[i][j] && grid[i][j]==1) {
                    maxArea=max(maxArea,area({i,j},visited,directions,grid));
                }
            }
        }
        return maxArea;
    }
};