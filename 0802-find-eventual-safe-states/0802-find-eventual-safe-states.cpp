class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        return safe(graph);
    }
    bool isCyclic(int st,vector<int> &visited,vector<vector<int>>& graph) {
        visited[st]=1;
        for(auto it:graph[st]) {
            if(visited[it]==-1) {
                if(isCyclic(it,visited,graph)) return true;
            } else if(visited[it]) {
                return true;
            }
        }
        visited[st]=0;
        return false;
    }
    vector<int> safe(vector<vector<int>>& graph) {
        vector<int> ans;
        for(int i=0;i<graph.size();i++) {
            vector<int> visited(graph.size(),-1);
            if(!isCyclic(i,visited,graph)) ans.push_back(i);
        }
        return ans;
    }
};