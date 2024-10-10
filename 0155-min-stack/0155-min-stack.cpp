class MinStack {
public:
    stack<long long int> st;
    long long int min;
    MinStack() {

    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            min=val;
            return;
        }
        if(val<min){
            st.push((long long int)2*val-min);
            min=val;
        }
        else{
            st.push(val);
        }
    }
    
    void pop() {
        if(st.empty())return;
        if(st.top()<min){
            min=(long long int)2*min-st.top();
            st.pop();
        }
        else{
            st.pop();
        }
    }
    
    int top() {
        if(st.empty())return -1;
        if(st.top()<min){
            return min;
        }
        else{
            return st.top();
        }
    }
    
    int getMin() {
        return min;
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