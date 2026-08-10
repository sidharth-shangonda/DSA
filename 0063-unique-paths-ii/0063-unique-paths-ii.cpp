class Solution {
public:
    // solve for small and you will undersatand for large 
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        bool isOne=false;
        for(int i=0;i<m;i++) {
            if(grid[i][0]==0 && isOne) grid[i][0]=1;
            else if(grid[i][0]==1) isOne=true;
        }
        isOne=false;
        for(int i=0;i<n;i++) {
            if(grid[0][i]==0 && isOne) grid[0][i]=1;
            else if(grid[0][i]==1) isOne=true;
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==0) grid[i][j]=1;
                else grid[i][j]=0;
            }
        }
        for(int i=1;i<m;i++) {
            for(int j=1;j<n;j++) {
                if(grid[i][j]==1) {
                    grid[i][j]=grid[i-1][j]+grid[i][j-1];
                }
            }
        }
        return grid[m-1][n-1];
    }
};