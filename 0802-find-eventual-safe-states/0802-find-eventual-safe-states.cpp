class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        return safe(graph);
    }
    bool isCyclic(int st,vector<int> &visited,vector<vector<int>>& graph,vector<int> &result) {
        visited[st]=1;
        for(auto it:graph[st]) {
            if(visited[it]==-1) {
                if(isCyclic(it,visited,graph,result)) return true;
            } else if(visited[it]) {
                return true;
            }
        }
        visited[st]=0;
        result.push_back(st);
        return false;
    }
    vector<int> safe(vector<vector<int>>& graph) {
        vector<int> ans;
        vector<int> visited(graph.size(),-1);
        for(int i=0;i<graph.size();i++) {
            if(visited[i]==-1) {
                if(!isCyclic(i,visited,graph,ans)) {
                    continue;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};