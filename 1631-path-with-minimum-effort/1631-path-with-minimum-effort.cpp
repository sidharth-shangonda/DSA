class Solution {
public:
    bool dfsHelper(int m,int n,pair<int,int> st,int &effort,vector<vector<bool>> &visited,vector<pair<int,int>> &directions,vector<vector<int>>& heights) {
        if(st.first==m-1 && st.second == n-1) return true;
        visited[st.first][st.second]=true;
        for(auto [dx,dy]:directions) {
            int cx=dx+st.first;
            int cy=dy+st.second;
            if(cx>=0 && cy>=0 && cx<m && cy<n && !visited[cx][cy] && abs(heights[cx][cy]-heights[st.first][st.second])<=effort) {
                if(dfsHelper(m,n,{cx,cy},effort,visited,directions,heights)) return true;
            } 
        }
        return false;
    }
    bool dfs(int &effort,vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        vector<pair<int,int>> directions={{0,-1},{0,1},{1,0},{-1,0}};
        if(dfsHelper(m,n,{0,0},effort,visited,directions,heights)) return true;
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        int low = 0;
        int high=INT_MIN;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                high=max(high,heights[i][j]);
            }
        }
        int ans = 0;
        while(low<=high) {
            int mid = low + (high - low) / 2;
            if(dfs(mid,heights)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};