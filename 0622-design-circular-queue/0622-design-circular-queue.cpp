class MyCircularQueue {
    vector <int> v;
    int left;
    int right;
    int k;
    int count=0;
public:
    MyCircularQueue(int k) {
        v.resize(k,-1);
        left=0;right=0;
        this->k=k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        if(v[right]==-1) {
            v[right]=value;
            count++;
            return true;
        }
        int idx=(right+1)%k;
        v[idx]=value;
        count++;
        right=idx;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        v[left]=-1;
        count--;
        if(left==right) return true;
        left=(left+1)%k;
        return true;
    }
    
    int Front() {
        return v[left];
    }
    
    int Rear() {
        return v[right];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */