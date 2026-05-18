class MinStack {
public:
    
    stack<int>st;
    stack<int>minSt;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minSt.empty()|| minSt.top()>=val ){
            minSt.push(val);
        }
    }
    
    void pop() {
        if(st.empty()){
            return ;
        }
        if(st.top()==minSt.top()){
            minSt.pop();
        }
        st.pop();
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        return st.top();
    }
    
    int getMin() {
       if(minSt.empty())return -1;
       return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */