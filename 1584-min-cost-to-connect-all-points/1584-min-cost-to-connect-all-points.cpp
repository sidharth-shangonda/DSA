class Solution {
public:
    //similar to prims but pointers approach
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int> dist(n,INT_MAX);
        int totalWt=0;
        for(int u=0;u<n-1;u++) {
            int x1=points[u][0];
            int y1=points[u][1];
            for(int v=u+1;v<n;v++) {
                int x2=points[v][0];
                int y2=points[v][1];
                int wt=abs(x1-x2)+abs(y1-y2);
                dist[v]=min(dist[v],wt);
                if(dist[u+1] > dist[v]) {//need min distance at i+1
                swap(points[u+1],points[v]);//now swat the points to the current so it this point is marked as done and do it unitl it is the smallest 
                swap(dist[u+1],dist[v]);//also the value at the dist
                }
            }
            totalWt+=dist[u+1];//now add the dist of i+1 to total wt
        }
        return totalWt;
    }
};