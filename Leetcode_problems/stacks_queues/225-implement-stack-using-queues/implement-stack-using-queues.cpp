class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int* ans = &q1.back();
        if(q1.front() == q1.back()){
            //only one element exist
            q1.pop();
            //cout<< "q1 front : "<< q1.front();
            return (*ans);
        }
        while(!(q1.empty())){
            if(&(q1.front()) == ans){
                q1.pop();
                break;
            }
            q2.push(q1.front());
            q1.pop();
        }
        while(!(q2.empty())){
            q1.push(q2.front());
            q2.pop();
        }
        return (*ans);
    }
    
    int top() {
        int ans = q1.back();
        return ans;
    }
    
    bool empty() {
        return(q1.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */