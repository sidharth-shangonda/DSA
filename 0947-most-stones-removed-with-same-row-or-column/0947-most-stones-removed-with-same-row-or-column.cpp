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
    void dfsHelper(int st,vector<bool> &visited,int &nodes) {
        nodes++;
        visited[st]=true;
        for(auto it:adj[st]) {
            if(!visited[it]) {
                dfsHelper(it,visited,nodes);
            }
        }
    }
    int dfs() {
        vector<bool> visited(V,false);
        int count=0;
        for(int i=0;i<V;i++) {
            if(!visited[i]) {
                int nodes=0;
                dfsHelper(i,visited,nodes);
                count+=nodes-1;
            }
        }
        return count;
    } 
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        Graph graph(n);
        for(int i=0;i<n-1;i++) {
            int x=stones[i][0];
            int y=stones[i][1];
            for(int j=i+1;j<n;j++) {
                int dx=stones[j][0];
                int dy=stones[j][1];
                if(x==dx || y == dy) {
                    graph.addEdge(i,j);
                }
            }
        }
        int total=graph.dfs();
        return total;
    }
};