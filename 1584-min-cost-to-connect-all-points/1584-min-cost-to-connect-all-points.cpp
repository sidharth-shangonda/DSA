class Graph {
public:
    int V;
    list<pair<int,int>> *adj;
    Graph(int V) {
        this->V=V;
        adj=new list<pair<int,int>>[V];
    }
    void addEdge(int u, int v,int wt) {
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    int prims() {
        set<int> visited; 
        int totalWeight=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()) {
            auto [wt,u]=pq.top();
            pq.pop();
            if(visited.count(u)) continue;
            totalWeight+=wt;
            visited.insert(u);
            if(visited.size()==V) break;
            for(auto [v,wt]:adj[u]) {
                if(!visited.count(v)) {
                    pq.push({wt,v});
                }
            }
        }
        return totalWeight;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        Graph graph(n);
        for(int u=0;u<n;u++) {
            int x1=points[u][0];
            int y1=points[u][1];
            for(int v=u+1;v<n;v++) {
                int x2=points[v][0];
                int y2=points[v][1];
                int wt=abs(x1-x2)+abs(y1-y2);
                graph.addEdge(u,v,wt);
            }
        }
        return graph.prims();
    }
};