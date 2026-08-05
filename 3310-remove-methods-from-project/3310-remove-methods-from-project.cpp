class Graph {
public:
    int V;
    list<int> *adj;
    vector<int> indeg;
    Graph(int V) {
        this->V=V;
        adj=new list<int>[V];
        indeg.resize(V);
    }
    void addEdge(int u,int v) {
        adj[u].push_back(v);
        indeg[v]++;
    }
    void dfsHelper(int st,vector<bool> &visited) {
        visited[st]=true;
        for(auto it:adj[st]) {
            indeg[it]--;
            if(!visited[it]) {
                dfsHelper(it,visited);
            } 
        }
    }
    vector<int> dfs(int k) {
        vector<bool> visited(V,false);
        dfsHelper(k,visited);
        vector<int> ans;
        bool rmbl=true;
        for(int i=0;i<V;i++) {
            if(visited[i] && indeg[i]!=0) {
                rmbl=false;
                break;
            } 
        }
        if(rmbl) {
            for(int i=0;i<V;i++) {
                if(!visited[i]) ans.push_back(i);
            }
        } else {
            for(int i=0;i<V;i++) {
                ans.push_back(i);
            }
        }
        return ans;
    }
    
};
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // DisjointSet sets(n);
        // for(auto &e:invocations) {
        //     sets.unionByRank(e[0],e[1]);
        // }
        // int sus=sets.find(k);
        // vector<int> ans;
        // vector<int> sol;
        // for(int i=0;i<n;i++) {
        //     if(sets.find(i)!=sus) ans.push_back(i);
        //     sol.push_back(i);
        // }

        Graph graph(n);
        for(auto &e:invocations) {
            graph.addEdge(e[0],e[1]);
        }
        return graph.dfs(k);
    }
};