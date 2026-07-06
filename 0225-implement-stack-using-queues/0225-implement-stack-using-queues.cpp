class MyStack {
public:
    deque<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push_back(x);
    }
    
    int pop() {
        if(q.size()!=0){
            int x=q.back();
            q.pop_back();
            return x;
        }
        return -1;
    }
    
    int top() {
        if(q.size()!=0) return q.back();
        return -1;
    }
    
    bool empty() {
        return q.size()==0;
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