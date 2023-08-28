class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        
        int n=q.size(); //[1,2,3,4,5]
        int tmp;
        while(n--)
        {
            tmp=q.front();
            q.pop();
            if(n>0)
                q.push(tmp);
        }
        return tmp;
    }
    
    int top() {
        int n=q.size(); //[1,2,3,4,5]
        int tmp;
        while(n--)
        {
            tmp=q.front();
            q.pop();
            q.push(tmp);
        }
        return tmp;
    }
    
    bool empty() {
        if(q.empty())
            return true;
        return false;
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