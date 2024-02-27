class MinStack {
public:
    stack<pair<int , long int> > s1;
    int min = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if (s1.empty() || val <= min) {
            min = val;
        }
        s1.push(make_pair(val, min));
    }
    
    void pop() {
        s1.pop();
        if (!s1.empty()) {
            min = s1.top().second;
        } else {
            min = INT_MAX; // Reset min if stack becomes empty
        }
    }

    
    int top() {
        return s1.top().first;
    }
    
    int getMin() {
        return (int)s1.top().second;
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