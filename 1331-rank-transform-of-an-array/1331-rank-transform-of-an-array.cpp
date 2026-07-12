class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector <int> temp=arr;
        sort(temp.begin(),temp.end());
        vector <int> ans;
        unordered_map<int,int> mp;
        int rank=1;
        for(int num:temp) {
            if(!mp.count(num)) {
                mp[num]=rank;
                rank++;
            }
        }
        for(int n:arr) {
            ans.push_back(mp[n]);
        }
        return ans;
    }
};