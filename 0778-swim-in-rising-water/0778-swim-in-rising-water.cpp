bool dfsHelper(pair<int,int> st,int t,vector<vector<bool>> &visited,vector<pair<int,int>> &directions,vector<vector<int>>& grid) {
    int n=grid.size();
    int x=st.first;
    int y=st.second;
    visited[x][y]=true;
    if(x==n-1 && y==n-1) {
        return true;
    }
    for(auto [dx,dy]:directions) {
        int cx=dx+x;
        int cy=dy+y;
        if(cx>=0 && cy>=0 && cx<n && cy<n && !visited[cx][cy] && grid[cx][cy]<=t) {//dont forget to implement the not visited 
            if(dfsHelper({cx,cy},t,visited,directions,grid)) return true;
        }
    }
    return false;
}
bool dfs (int t,vector<vector<int>>& grid) {
    int n=grid.size();
    vector<pair<int,int>> directions={{-1,0},{0,1},{1,0},{0,-1}};
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    if(dfsHelper({0,0},t,visited,directions,grid)) return true;
    return false;
}
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int low=grid[0][0];
        int high=n*n;
        int ans=INT_MAX;
        while(low<=high) {
            int mid=low + (high - low)/2;
            if(dfs(mid,grid)) {
                ans=mid;
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return ans;
    }
};