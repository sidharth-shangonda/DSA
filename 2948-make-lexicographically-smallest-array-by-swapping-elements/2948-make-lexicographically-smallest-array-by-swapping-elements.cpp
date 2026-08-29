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
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int,int>> ans;
        for(int i=0;i<n;i++) {
            ans.push_back({nums[i],i});
        }
        DisjointSet sets(n);
        //O(n) to insert into dsu
        sort(ans.begin(),ans.end());
        for(int i=1;i<n;i++) {
            if(abs(ans[i-1].first-ans[i].first)<=limit) sets.unionByRank(ans[i-1].second,ans[i].second);
        }
        unordered_map<int,vector<int>> groups;
        for(int i=0;i<n;i++) {
            groups[sets.find(i)].push_back(i);
        }
        for(auto &group : groups) {

            vector<int>& indices = group.second;
            // Get values of this component
            vector<int> values;
            for(int idx : indices) {
                values.push_back(nums[idx]);
            }
            // Sort positions and values
            sort(indices.begin(), indices.end());
            sort(values.begin(), values.end());
            // Step 4: Put smallest values at smallest positions
            for(int i = 0; i < indices.size(); i++) {
                nums[indices[i]] = values[i];
            }

        }
        return nums;
    }
};