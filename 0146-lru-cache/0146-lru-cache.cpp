class Node {
public:
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int key,int value) {
        this->key=key;
        this->value=value;
        this->next=NULL;
        this->prev=NULL;
    }

};
class LRUCache {
    int size;
    unordered_map<int,Node*> mp;
    Node* ed;
    Node* st;
public:
    LRUCache(int capacity) {
        this->size = capacity;
        st=NULL;
        ed=NULL;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        int value=mp[key]->value;
        replace(key);
        return value;
    }
    
    void put(int key, int value) {
        if(mp.count(key)) {
            mp[key]->value=value;
            replace(key);
            return;
        }
        if(mp.size()==size) {
            deleteNode();
        }
        addNode(key,value);
    }
    void addNode(int key,int value) {
        Node* newNode=new Node(key,value);
        if(st==NULL) {
            mp[key]=newNode;
            st=newNode;
            ed=newNode;
            return;
        }
        st->next=newNode;
        newNode->prev=st;
        st=newNode;
        mp[key]=newNode;
    }
    void deleteNode() {
        if(ed==NULL ) return;
        Node* temp=ed;
        if(ed==st) {
            ed=NULL;
            st=NULL;
        } else {
            ed=ed->next;
            ed->prev=NULL;
        }
        mp.erase(temp->key);
        delete temp;
    }
    void replace(int key) {
        Node* node=mp[key];
        if(node==st) return;
        //if the curreent node is lru
        if(node==ed) {
            ed=ed->next;
            ed->prev=NULL;
        } else {
            node->next->prev=node->prev;
            node->prev->next=node->next;
        }
        //shift to MRU
        st->next=node;
        node->prev=st;
        node->next=NULL;
        st=node;
                
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */