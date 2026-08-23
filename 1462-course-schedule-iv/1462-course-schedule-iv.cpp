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
    void kahnsAlgo(vector<vector<bool>> &dp) {
        queue<int> q;
        for(int i=0;i<V;i++) {
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()) {
            int cur=q.front();
            q.pop();
            for(auto it:adj[cur]) {
                dp[cur][it]=true;
                for(int x=0;x<V;x++) {
                    if(dp[x][cur]) dp[x][it]=true;
                }
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        //there is no cycle
        // if(ans.size()!=V) {
        //     cout<<"Graph has a cycle, topological sort not possible."<<endl;
        //     return {};
        // }
    }
};
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        Graph g(numCourses);
        for(auto it:prerequisites) {
            g.addEdge(it[0],it[1]);
        }
        vector<vector<bool>> dp(numCourses,vector<bool>(numCourses,false));
        g.kahnsAlgo(dp);
        vector<bool> ans;
        for(auto &e:queries) {
            if(dp[e[0]][e[1]]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};