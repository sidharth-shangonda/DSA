class MyHashMap {
    vector<pair<int,int>> mp;
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        for(auto &it:mp) { //use & to change values 
            if(key==it.first) {
                it.second=value;
                return;
            }
        }
        mp.push_back(make_pair(key,value));
    }
    
    int get(int key) {
        for(auto it:mp) {
            if(key==it.first) return it.second;
        }
        return -1;
    }
    
    void remove(int key) {
        auto it = find_if(mp.begin(),mp.end(),[&](const pair<int,int> &a){
            return a.first==key;
        });
        if(it!=mp.end()) {
            mp.erase(it);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */