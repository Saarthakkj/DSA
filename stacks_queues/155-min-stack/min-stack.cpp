class MinStack {
public:
    stack<int> s1;
    vector<int> v;
    MinStack() {
        
    }
    
    void push(int val) {
        s1.push(val);
        v.push_back(val);
    }
    
    void pop() {
        s1.pop();
        v.pop_back();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return (*min_element(v.begin() , v.end()));
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