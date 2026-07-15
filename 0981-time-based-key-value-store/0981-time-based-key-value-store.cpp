class TimeMap {
    unordered_map<string,vector<pair<int ,string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(timestamp,value));
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) return "";//make sure of the edge case
        int low=0;
        int high=mp[key].size()-1;
        int ans=-1;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(mp[key][mid].first<=timestamp) {
                ans=mid;
                low=mid+1;
            } else {
                high=mid-1;
            }
        }
        if(ans==-1) return "";
        return mp[key][ans].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */