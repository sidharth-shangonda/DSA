class FreqStack {
    //make sure you under stand the requirement 
   unordered_map<int,int> freq;
   unordered_map< int, stack <int> > group;
   int maxFreq;
public:
    FreqStack() {

    }

    void push(int val) {
        freq[val]++;
        group[freq[val]].push(val);
        if(freq[val]>maxFreq) maxFreq=freq[val];
    }
    
    int pop() {
        int top=group[maxFreq].top();
        freq[top]--;//dont forget to decrease it 
        group[maxFreq].pop();
        if(group[maxFreq].empty()) maxFreq--;
        return top;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */