class Graph{
public:
    int V;
    list<int> *adj;
    Graph(int V) {
        this->V=V;
        adj=new list<int>[V];
    }
    void addEdge(int u,int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfsHelper(int st,vector<bool> &visited) {
        visited[st]=true;
        for(auto it:adj[st]) {
            if(!visited[it]) {
                dfsHelper(it,visited);
            }
        }
    }
    int dfs() {
        vector<bool> visited(V,false);
        int count=0;
        for(int i=0;i<V;i++) {
            if(!visited[i]) {
                dfsHelper(i,visited);
                count++;
            }
        }
        return count;
    } 
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int size=connections.size();
        if(size<n-1) return -1;
        Graph graph(n);
        for(auto &e:connections) {
            graph.addEdge(e[0],e[1]);
        }
        int total=graph.dfs();
        return total-1;
    }
};