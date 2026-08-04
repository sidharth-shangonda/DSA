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
        if(parA ==parB) return;
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
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        DisjointSet sets(n);
        for(int i=0;i<n-1;i++) {
            int x=stones[i][0];
            int y=stones[i][1];
            for(int j=i+1;j<n;j++) {
                int dx=stones[j][0];
                int dy=stones[j][1];
                if(x==dx || y == dy) {
                    sets.unionByRank(i,j);
                }
            }
        }
        set <int> unique;
        for(int i=0;i<n;i++) {
            if(!unique.count(sets.find(i))) unique.insert(sets.find(i));//dont implemet the i insert the parent sets.find(i)
        }
        return n-unique.size();//return the n - total subgraphs
    }
};