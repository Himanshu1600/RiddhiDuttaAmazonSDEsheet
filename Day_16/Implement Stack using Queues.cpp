class MyStack {
public:
    queue<int>q;
    int topnum;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        topnum=x;
    }
    
    int pop() {
        int n=q.size();
        n--;
        while(n--){
            int temp=q.front();
            q.pop();
            q.push(temp);
            topnum=temp;
        }
        int result=q.front();
        q.pop();
        return result;
    }
    
    int top() {
        return topnum;
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
