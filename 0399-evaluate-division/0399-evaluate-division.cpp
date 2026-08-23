class DisjointSet{
public:
    vector<int> parent,rank;
    DisjointSet(int n) {
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++) {
            parent[i]=i;
        }
    }
    int find(int x) {
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);//path compression
    }
    void unionByRank(int u,int v) {
        int parA=find(u);
        int parB=find(v);
        if(parA==parB) return;
        if(rank[parA] < rank[parB]) {
            parent[parA]=parB;
        } else if(rank[parA] > rank[parB]) {
            parent[parB]=parA;
        } else {
            parent[parB]=parA;
            rank[parA]++;
        }
    }
};
class Graph {
public:
    int V;
    vector<int> indegree;
    list<pair<int,double>> *adj;
    Graph(int V) {
        this->V=V;
        adj=new list<pair<int,double>>[V];
        indegree.resize(V,0);
    }
    void addEdge(int u,int v,double wt){
        adj[u].push_back({v,wt});
        adj[v].push_back({u,1.0/wt});
        indegree[u]++;
        indegree[v]++;
    }
    void dfs(

        int src,

        int u,

        double product,

        vector<bool>& visited,

        vector<vector<double>>& dp

    ) {

        visited[u] = true;

        // src / u = product

        dp[src][u] = product;

        for(auto [v, wt] : adj[u]) {

            if(visited[v])

                continue;

            dfs(

                src,

                v,

                product * wt,

                visited,

                dp

            );

        }

    }
    void buildDP(vector<vector<double>>& dp) {

        for(int src = 0; src < V; src++) {

            vector<bool> visited(V, false);

            dfs(

                src,

                src,

                1.0,

                visited,

                dp

            );

        }

    }
    
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int> mp;
        int x=1;
        for(auto &e:equations) {
            if(!mp.count(e[0])) {
                mp[e[0]]=x;
                x++;
            }
            if(!mp.count(e[1])) {
                mp[e[1]]=x;
                x++;
            }
        }
        int V=mp.size();
        Graph g(V+1);//create a graphs
        DisjointSet sets(V+1);//get all disconnected graphs also
        for(int i=0;i<equations.size();i++) {
            g.addEdge(mp[equations[i][0]],mp[equations[i][1]],values[i]);
            sets.unionByRank(mp[equations[i][0]],mp[equations[i][1]]);
        }
        vector<vector<double>> dp(V+1,vector<double>(V+1,-1));
        g.buildDP(dp);
        vector<double> ans;

        for(auto &q : queries) {

            // Variable doesn't exist

            if(!mp.count(q[0]) || !mp.count(q[1])) {

                ans.push_back(-1.0);

                continue;

            }

            int u = mp[q[0]];

            int v = mp[q[1]];

            // Different components

            if(sets.find(u) != sets.find(v)) {

                ans.push_back(-1.0);

                continue;

            }

            // Same component

            ans.push_back(dp[u][v]);

        }

        return ans;
    }
};