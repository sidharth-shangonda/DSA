class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const int MOD = 1e9 + 7;

        vector<vector<pair<int,int>>> graph(n);

        for(auto &e : roads){
            graph[e[0]].push_back({e[1],e[2]});
            graph[e[1]].push_back({e[0],e[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});

        while(!pq.empty()){

            auto [d,u] = pq.top();
            pq.pop();

            if(d > dist[u])
                continue;

            for(auto [v,wt] : graph[u]){

                long long newDist = d + wt;

                if(newDist < dist[v]){

                    dist[v] = newDist;
                    ways[v] = ways[u];

                    pq.push({newDist,v});
                }

                else if(newDist == dist[v]){

                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n-1];
    }
};