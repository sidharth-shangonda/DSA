class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // Step 1: Build the adjacency list
        // adj[i] will store pairs of {neighbor, distance}
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        
        // Step 2: Initialize BFS
        queue<int> q;
        vector<bool> visited(n + 1, false);
        
        q.push(1);
        visited[1] = true;
        
        int min_score = INT_MAX;
        
        // Step 3: Traverse the graph
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (const auto& [neighbor, distance] : adj[curr]) {
                // Update minimum score with every edge we encounter
                min_score = min(min_score, distance);
                
                // If the neighbor hasn't been visited, add it to the queue
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        return min_score;
    }
};