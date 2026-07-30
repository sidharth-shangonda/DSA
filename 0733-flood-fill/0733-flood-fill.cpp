class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        vector<pair<int, int>> directions = {
                                                {-1, 0}, // Up
                                                {0, 1},  // Right
                                                {1, 0},  // Down
                                                {0, -1}  // Left
                                            };
        queue<pair<int ,int>>q;
        q.push({sr,sc});
        visited[sr][sc]=true;
        int req=image[sr][sc];
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            image[x][y]=color;
            for(auto [dx,dy]:directions) {
                int cx=dx+x;
                int cy=dy+y;
                if(cx>=0 && cy>=0 && cx<m && cy<n && image[cx][cy]==req && !visited[cx][cy] ) {
                    visited[cx][cy]=true;
                    q.push({cx,cy});
                }
            }
        }
        return image;
    }
};