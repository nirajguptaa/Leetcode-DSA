class FreqStack {
public:
    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>groups;
    int maxFreq=0;
    FreqStack() {
    }
    
    void push(int val) {
        freq[val]++;
        int freqEle=freq[val];
        groups[freqEle].push(val);
        maxFreq=max(maxFreq,freqEle);

    }
    
    int pop() {
        
        int popVal=groups[maxFreq].top();
        freq[popVal]--;
        groups[maxFreq].pop();
        if(groups[maxFreq].empty())maxFreq--;
        return popVal;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */