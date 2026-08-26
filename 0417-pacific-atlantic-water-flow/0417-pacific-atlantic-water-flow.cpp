class Solution {
public:
    void bfs(pair<int,int> st,vector<vector<bool>> &visited,vector<pair<int,int>> &directions,vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        queue<pair<int,int>> q;
        visited[st.first][st.second]=true;
        q.push({st.first,st.second});
        while(!q.empty()) {
            auto[x,y]=q.front();
            q.pop();
            for(auto [dx,dy]:directions) {
                int cx=x+dx;
                int cy=y+dy;
                if(cx>=0 && cy>=0 && cx<m && cy<n && !visited[cx][cy] && heights[x][y]<=heights[cx][cy]) {
                    visited[cx][cy]=true;
                    q.push({cx,cy});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<pair<int,int>> directions={{-1,0},{0,1},{1,0},{0,-1}};
        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));
        //pacific
        for(int i=0;i<m;i++) {
            bfs({i,0},pacific,directions,heights);
        }
        for(int i=0;i<n;i++){
            bfs({0,i},pacific,directions,heights);
        }
        //atlantic
        for(int i=0;i<m;i++) {
            bfs({i,n-1},atlantic,directions,heights);
        }
        for(int i=0;i<n;i++){
            bfs({m-1,i},atlantic,directions,heights);
        }
        vector<vector<int>> ans;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};