class Solution {
public:
    bool bfs(int start,vector<vector<int>>& graph,vector <bool> &visited,vector<int> &color) {
        queue<int> q;
        q.push(start);
        visited[start]=true;
        color[start]=0;
        while(!q.empty()) {
            auto cur=q.front();
            q.pop();
            int same=color[cur];
            int opp=(same+1)%2;
            for(auto it:graph[cur]) {
                if(!visited[it]) {
                    visited[it]=true;
                    color[it]=opp;
                    q.push(it);//you always forget to push dont forget it 
                } else if(color[it]==same) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector <bool> visited(n,false);
        vector<int> color(n,-1);
        for(int i=0;i<n;i++) {
            if(!visited[i]){
                if(!bfs(i,graph,visited,color)) return false;
            }
        }
        return true;
    }
};