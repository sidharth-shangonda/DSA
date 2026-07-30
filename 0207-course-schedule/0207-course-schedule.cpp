class Graph{
public:
    int V;
    list<int> *adj;
    bool cyclePresent=false;
    Graph(int V) {
        this->V=V;
        adj=new list<int>[V];
    }
    void addEdge(int u,int v) {
        adj[u].push_back(v);
    }
    void detectCycleHelper(int st,vector<int> &visited,vector<int> &pathVisited) {
        visited[st]=true;
        pathVisited[st]=true;
        for(auto it:adj[st]) {
            if(!visited[it]) {
                detectCycleHelper(it,visited,pathVisited);
            } else if(pathVisited[it]) {// different for undirected graph
                cyclePresent=true;
                return;
            }
        }
        pathVisited[st] = false;//after recursion so this also
     } 
    void detectCycle() {
        vector<int> visited(V,false);
        vector<int> pathVisited(V,false);
        for(int i=0;i<V;i++) {
            if(!visited[i]) {
                detectCycleHelper(i,visited,pathVisited);
            }
        }
    }
};
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g(numCourses);
        for(auto it:prerequisites) {
            g.addEdge(it[1],it[0]);//not a->b ots b->a
        }
        g.detectCycle();
        return g.cyclePresent ? false:true;
    }
};