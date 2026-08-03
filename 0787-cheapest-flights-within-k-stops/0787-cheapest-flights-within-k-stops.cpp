class Edge {
public: 
    int v;
    int wt;
    Edge(int v,int wt)  {
        this->v=v;
        this->wt=wt;
    }
};
    void dijkshtra(int &src,int &dst,int &k,vector<int> &dist,vector<vector<Edge>> &graph) {
        queue<pair<int,int>> pq;
        pq.push({0,src});
        dist[src]=0;
        while(!pq.empty()) {
            int size=pq.size();
            while(size--) {
                auto [dist_u,u]=pq.front();
                pq.pop();
                for(auto [v,wt]:graph[u]) {
                    if(dist[v]>dist_u+wt) {
                        dist[v]=dist_u+wt;
                        if(k>0) pq.push({dist[v],v});//only k>0 not for zero 
                    }
                }
            }
            k--;
        }
    }
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<Edge>> graph(n);
        for(auto edge:flights) {
            graph[edge[0]].push_back(Edge(edge[1],edge[2]));
        }
        vector<int> dist(n,INT_MAX);
        dijkshtra(src,dst,k,dist,graph);
        if(dist[dst]==INT_MAX) return -1;//dst
        return dist[dst];
    }
};