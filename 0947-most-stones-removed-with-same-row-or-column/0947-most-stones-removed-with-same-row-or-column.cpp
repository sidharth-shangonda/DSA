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
        int maxRow=0;
        int maxCol=0;
        int n=stones.size();
        for(auto &e:stones) {
            maxRow=max(maxRow,e[0]);
            maxCol=max(maxCol,e[1]);
        }
        int columOfset=maxRow+1;
        int totalNodes=columOfset+maxCol+1;
        DisjointSet sets(totalNodes);
        set <int> usedNodes;
        for(int i=0;i<n;i++) {
           int row=stones[i][0];
           int col=columOfset+stones[i][1];
           sets.unionByRank(row,col);
           usedNodes.insert(row);
           usedNodes.insert(col);
        }
        // set <int> unique;
        //always dont use extraspace to count unique sets just use find(i)==i and count++
        int components=0;
        for(auto i:usedNodes) {
            if(sets.find(i) == i) components++;//dont implemet the i insert the parent sets.find(i)
        }
        return n-components;//return the n - total subgraphs
    }
};