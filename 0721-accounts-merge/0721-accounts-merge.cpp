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
        if(parA==parB) return;
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet sets(n);
        // This is very complicated implement 

        // unordered_map<int,unorderd_set<string>> mp;
        // for(int i=1;i<accounts[0].size();i++) {
        //     mp[0].insert(accounts[0][i]);
        // }
        // for(int i=0;i<n-1;i++) {
        //     for(int j=i+1;j<n;j++) {
        //         for(int k=1;k<accounts[j],size();k++) {
        //             mp[j].insert(accounts[j][k]);
        //             if(mp[i].count(accounts[j][k])) {
        //                 sets.unionByRank(i,j);
        //             }
        //         }
        //     }
        // }
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++) {
            for(int k=1;k<accounts[i].size();k++) {
                if(mp.count(accounts[i][k])) {
                    sets.unionByRank(mp[accounts[i][k]],i);
                } else {
                    mp[accounts[i][k]]=i;
                }
            }
        }
        set<int> s;
        for(int i=0;i<n;i++) {
            int parI=sets.find(i);
            if(!s.count(parI)) s.insert(parI);
        }
        for(auto it:mp) {
            int i=it.second;
            int parI=sets.find(i);
            if(i==parI) continue;
            accounts[parI].push_back(it.first);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(s.count(i)) {
                sort(accounts[i].begin()+1,accounts[i].end());
                // usnique is used to store only inique values 
                accounts[i].erase(unique(accounts[i].begin() + 1, accounts[i].end()),accounts[i].end());
                ans.push_back(accounts[i]);
            }
        }
        return ans;
    }
};