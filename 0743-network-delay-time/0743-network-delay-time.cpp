class Edge {
public: 
    int v;
    int wt;
    Edge(int v,int wt)  {
        this->v=v;
        this->wt=wt;
    }
};
    void dijkshtra(int &src,vector<int> &dist,vector<vector<Edge>> &graph) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        dist[src]=0;
        while(!pq.empty()) {
            auto [dist_u,u]=pq.top();
            pq.pop();
            if(dist[u]<dist_u) continue;//this singel line can save much more complexity
            for(auto [v,wt]:graph[u]) {
                if(dist[v]>dist_u+wt) {
                    dist[v]=dist_u+wt;
                    pq.push({dist[v],v}); 
                }
            }
        }
    }
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<Edge>> graph(n+1);
        for(auto edge:times) {
            graph[edge[0]].push_back(Edge(edge[1],edge[2]));
        }
        vector<int> dist(n+1,INT_MAX);
        dijkshtra(k,dist,graph);
        int time=-1;
        for(int i=1;i<=n;i++) {
            if(i==k) continue;
            if(dist[i] >= INT_MAX) return -1;
            time=max(time,dist[i]);
        }
        return time;
    }
};