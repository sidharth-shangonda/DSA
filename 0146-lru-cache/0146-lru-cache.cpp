class Node {
public:
    int key;
    int value;
    Node* left;
    Node* right;
    Node(int key,int value) {
        this->key = key;
        this->value = value;
        left = NULL;
        right = NULL;
    }
};
class LRUCache {
public:
    unordered_map<int,Node*> mp;
    int size;
    Node* st;
    Node* end;
    LRUCache(int capacity) {
        this->size = capacity;
        st = NULL;
        end = NULL;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        int value = mp[key]->value;
        replace(key);
        return value;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            mp[key]->value = value;
            replace(key);
            return;
        }
        if(mp.size() == size) deleteNode();
        addNode(key,value);
    }
    void addNode(int key,int value) {
        Node *newNode = new Node(key,value);
        if(st == nullptr) {
            st = end = newNode;
            mp[key] = newNode;
            return;
        }
        st->right = newNode;
        newNode->left = st;
        st = newNode; 
        mp[key] = newNode;
    }
    void deleteNode() {
        if(end == nullptr) return ;
        Node* temp = end;
        if(end == st) {
            st = end = nullptr;
        } else {
            end=end->right;
            end->left=nullptr;
        }
        mp.erase(temp->key);
        delete temp;
    }

    void replace(int key) {
        Node* node = mp[key];
        if(node == st) return;
        if(node == end) {
            end = end->right;
            end->left=nullptr;
        } else {
            node->left->right = node->right;
            node->right->left = node->left;
        }
        // make mru
        st->right = node;
        node->left = st;
        node->right = NULL;
        st = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */