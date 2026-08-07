class DisjointSet {
public:
    vector<int> rank,parent;
    DisjointSet (int n) {
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++) {
            parent[i]=i;
        }
    }

    int find(int x) {
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);//path compression
    }
    void unionByRank(int u,int v) {
        int parU=find(u);
        int parV=find(v);
        if(parU==parV) return;
        if(rank[parU]>rank[parV]) {
            parent[parV]=parU;
        } else if(rank[parU]<rank[parV]) {
            parent[parU]=parV;
        } else {
            parent[parV]=parU;
            rank[parU]++;
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet sets(n*n);
        // vector<vector<bool>> visited(n,vector<bool>(n,false));
        vector<pair<int,int>> directions={{-1,0},{0,1},{1,0},{0,-1}};
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    if(i+1 < n &&grid[i+1][j]==1) sets.unionByRank(i*n+j,(i+1)*n+j);
                    if(j+1<n && grid[i][j+1]==1) sets.unionByRank(i*n+j,i*n+j+1);
                }
            }
        }
        int maxArea=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    int par=sets.find(i*n+j);
                    mp[par]++;
                    maxArea=max(maxArea,mp[par]);
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==0) {
                    int area=1;//include 0 
                    unordered_set<int> s;
                    for(auto [di,dj]:directions) {
                        int ci=di+i;
                        int cj=dj+j;
                        if(ci>=0 && cj>=0 && ci<n && cj<n && grid[ci][cj]) {
                            int par=sets.find(ci*n+cj);
                            s.insert(par);
                            // area+=mp[par];//this is error prone an calculate duplicates
                        }
                    }
                    for(auto it:s) {
                        area+=mp[it];
                    }
                    maxArea=max(maxArea,area);
                }
            }
        }
        return maxArea?maxArea:1;//dont foget edge case
    }
};