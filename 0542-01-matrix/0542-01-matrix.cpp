class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<pair<int,int>> directions={{-1, 0},{0,1},{1,0},{0,-1}};
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(mat[i][j] == 0) {
                    q.push({i,j});
                    visited[i][j]=true;
                }
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
                    if(cx>=0 && cy>=0 && cx<m && cy<n && !visited[cx][cy]) {
                        // mat[cx][cy]+=mat[x][y]; this is also correct but use this standard one
                        mat[cx][cy]=mat[x][y]+1;
                        visited[cx][cy]=true;
                        q.push({cx,cy});
                    }
                }
            }
        }
        return mat;
    }
};