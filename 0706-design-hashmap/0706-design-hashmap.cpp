class MyHashMap {
    static const int SIZE = 1009;//wiil be easier to choose prime 
    vector<vector<pair<int,int>>> table; //stores buckets 

public:
    MyHashMap() {
        table.resize(SIZE);
    }

    void put(int key, int value) {
        int idx = key % SIZE;

        for (auto &p : table[idx]) {//use & to change the value 
            if (p.first == key) {
                p.second = value;
                return;
            }
        }

        table[idx].push_back({key, value});
    }

    int get(int key) {
        int idx = key % SIZE;

        for (auto &p : table[idx]) {
            if (p.first == key)
                return p.second;
        }

        return -1;
    }

    void remove(int key) {
        int idx = key % SIZE;

        auto &bucket = table[idx];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};