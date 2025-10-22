class MyStack {
public:
    queue<int> q;

    MyStack() {}
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int size = q.size();
        for(int i = 0; i < size - 1; i++){
            int top = q.front();
            q.pop();
            q.push(top);
        }
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};