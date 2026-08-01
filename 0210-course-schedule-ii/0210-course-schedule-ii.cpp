class Graph {
public:
    int V;
    list<int> *adj;
    Graph(int V) {
        this->V=V;
        adj=new list<int>[V];
    }
    void addEdge(int u,int v) {
        adj[u].push_back(v);
    }
    bool isCyclicHelper(int st,vector<int> &path) {
        path[st]=1;
        for(auto it:adj[st]) {
            if(path[it]==-1) {
                if(isCyclicHelper(it,path)) return true;
            } else if(path[it]) {
                return true;
            }
        }
        path[st]=0;
        return false;
        
    }
    bool isCyclic() {
        vector<int> path(V,-1);
        for(int i=0;i<V;i++) {
            if(path[i]==-1) {
                if(isCyclicHelper(i,path)) return true;
            }
        }
        return false;
    }
    void topoSortHelper(int st,vector<bool> &visited,stack<int> &s) {
        visited[st]=true;
        for(auto it:adj[st]) {
            if(!visited[it]) {
                topoSortHelper(it,visited,s);
            }
        }
        s.push(st);
    }
    
    vector<int> topoSort() {
        vector<bool> visited(V,false);
        stack<int> s;
        for(int i=0;i<V;i++) {
            if(!visited[i]) {
                topoSortHelper(i,visited,s);
            }
        }
        vector<int> ans;
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         Graph g(numCourses);
        for(auto it:prerequisites) {
            g.addEdge(it[1],it[0]);//not a->b ots b->a
        }
        if(g.isCyclic()) return {};
        return g.topoSort();
    }
};