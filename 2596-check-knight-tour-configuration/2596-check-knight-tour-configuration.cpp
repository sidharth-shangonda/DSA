class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!=0) return false;
        int n=grid.size();
        vector<pair<int,int>> directions={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
        int x=0,px=0;
        int y=0,py=0;
        int i=1;
        while(i <= n*n-1) {
            for(auto [dx,dy]:directions) {
                int cx=x+dx;
                int cy=y+dy;
                if(cx>=0 && cy>=0 && cx<n && cy<n && grid[cx][cy]==i) {
                    y=cy;
                    x=cx;
                    break;
                }
            }
            if(px==x && py==y) return false;
            px=x;
            py=y;
            i++;
        }
        return true;
    }
};