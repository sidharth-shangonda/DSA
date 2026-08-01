class Graph {
public:
    int V;
    list<int> *adj;
    vector<int> indegree;
    Graph(int V)  {
        this->V=V;
        adj=new list<int>[V];
        indegree.resize(V,0);
    }
    void addEdge(int u,int v) {
        adj[u].push_back(v);
        indegree[v]++;
    }
    // using bfs
    vector<int> kahnsAlgo() {
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<V;i++) {
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()) {
            int cur=q.front();
            q.pop();
            ans.push_back(cur);
            for(auto it:adj[cur]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(ans.size()!=V) {
            cout<<"Graph has a cycle, topological sort not possible."<<endl;
            return {};
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
        
        return g.kahnsAlgo();
    }
};