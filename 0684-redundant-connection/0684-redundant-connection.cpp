class DisjointSet {
public:
    vector<int> rank,parent;
    DisjointSet(int n) {
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++) {
            parent[i]=i;
        }
    }
    int find(int x) {
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    bool unionByRank(int a,int b) {
        int parA=find(a);
        int parB=find(b);
        if(parA==parB) return false;
        if(rank[parA]>rank[parB]) {
            parent[parB]=parA;
        } else if(rank[parA]<rank[parB]) {
            parent[parA]=parB;
        } else {
            parent[parB]=parA;
            rank[parA]++;
        }
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        DisjointSet sets(n);
        for(auto e:edges) {
            if(!sets.unionByRank(e[0],e[1])) return e;
        }
        return {0,0};
    }
};