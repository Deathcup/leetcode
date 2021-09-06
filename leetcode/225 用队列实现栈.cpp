class MyStack {
public:
	queue<int> que;
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
		que.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
		int size = que.size();
		size--;
		while (size--){
			int t = que.front();
			que.pop();
			que.push(t);
		}
		int t = que.front();
		que.pop();
		return t;
    }
    
    /** Get the top element. */
    int top() {
		int t = this -> pop();
		que.push(t);
		return t;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
		return que.empty();
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
