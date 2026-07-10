class MyHashSet {
    int size=1009;
    vector<vector<int>> table;
public:
    MyHashSet() {
        table.resize(size);
    }
    
    void add(int key) {
        int idx=key%size;
        if(!contains(key)) table[idx].push_back(key);
    }
    
    void remove(int key) {
        int idx=key%size;
        auto &bucket=table[idx];
        auto it=find(bucket.begin(),bucket.end(),key);
        if(it!=bucket.end()) bucket.erase(it);
    }
    
    bool contains(int key) {
        int idx=key%size;
        for(auto it:table[idx]) {
            if(key==it) return true; 
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */