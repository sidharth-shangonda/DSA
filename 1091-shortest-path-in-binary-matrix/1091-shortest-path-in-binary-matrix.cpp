class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1]==1) return -1;
        if(n==1) return 1;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        vector<pair<int, int>> directions = {
                                                {1, 0},    // Down
                                                {1, 1},    // Down-Right
                                                {1, -1},   // Down-Left
                                                {0, 1},    // Right
                                                {0, -1},   // Left
                                                {-1, 0},   // Up
                                                {-1, 1},   // Up-Right
                                                {-1, -1}   // Up-Left
                                            };
        queue <pair<int,int>> q;
        q.push({0,0});
        visited[0][0] = true;
        int dist=0;
        while(!q.empty()) {
            int size=q.size();
            dist++;
            while(size--) {
                auto [x,y] = q.front();
                q.pop();
                for(auto [dx,dy]:directions) {
                    int cx=dx+x;
                    int cy=dy+y;
                    if(cx == n-1 && cy == n-1) return dist+1;
                    if(cx>=0 && cy>=0 && cx<n && cy<n && !visited[cx][cy] && grid[cx][cy] == 0 ) {
                        visited[cx][cy]=true;
                        q.push({cx,cy});
                    }
                }
            }
        }
        return -1;
    }
};