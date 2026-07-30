class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<pair<int, int>> directions = {{-1, 0},{0, 1},{1, 0}, {0, -1} };
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        int fresh=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==2) {
                    q.push({i,j});
                } else if(grid[i][j]==1) {
                    fresh++;
                }
            }
        }
        
        int minutes=0;
        while(!q.empty()) {
            int size=q.size();
            bool rotten=false;
            while(size--){
                auto [x,y]=q.front();
                q.pop();
                for(auto [dx,dy]:directions) {
                    int cx=x+dx;
                    int cy=y+dy;
                    if(cx>=0 && cx<m && cy>=0 && cy<n && grid[cx][cy] == 1 && !visited[cx][cy]) {
                        visited[cx][cy]=true;
                        grid[cx][cy]=2;
                        rotten=true;
                        fresh--;//to count the total freash
                        q.push({cx,cy});
                    }
                }
            }
            if(rotten) minutes++;
        }
        return fresh==0?minutes:-1;
    }
};