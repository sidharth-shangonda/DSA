class Graph {
public:
    int V;
    list<int> *adj;
    vector<int> deg;
    Graph(int V) {
        this->V=V;
        adj=new list<int>[V];
        deg.resize(V,0);
    }
    void addEdges(int u,int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    vector<int> lot() {
        queue<int> q;
        // vector<bool> visited(V,false);
        vector<pair<int,int>> ans;
        for(int i=0;i<V;i++) {
            if(deg[i]==1) {
                q.push(i);
                // visited[i]=true;
            }
        }
        int level=0;
        while(!q.empty()) {
            int size=q.size();
            for(int i=0;i<size;i++) {
                int u=q.front();
                q.pop();
                ans.push_back({u,level});
                for(auto v:adj[u]) {
                    deg[v]--;
                    if(deg[v]==1) {
                    q.push(v);
                    }
                }
            }
            level++;
        }
        vector<int> result;
        if(ans.empty()) return result;
        int middle=ans.back().second;
        while(!ans.empty() && ans.back().second==middle) {
            result.push_back(ans.back().first);
            ans.pop_back();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        Graph g(n);
        for(auto &e:edges) {
            g.addEdges(e[0],e[1]);
        }
        vector<int> ans=g.lot();
        return ans;
    }
};