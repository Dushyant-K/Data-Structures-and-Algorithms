class MyStack {
    private:
    queue<int> q;
    int size;
public:
    MyStack() {

    }    
    void push(int x) {
        size = q.size();
        q.push(x);
        for(int i=1;i<=size;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int e = q.front();
        q.pop();
        return e;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
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