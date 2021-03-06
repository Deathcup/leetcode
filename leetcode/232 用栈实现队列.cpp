class MyQueue {
public:
	stack<int> instack;
	stack<int> outstack; 
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
		instack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
		if (outstack.empty()){
			while (!instack.empty()){
				int tmp = instack.top();
				instack.pop();
				outstack.push(tmp);
			}
		}
		if (!outstack.empty()){
			int res = outstack.top();
			outstack.pop();
			return res;
		}
		return -1;
    }
    
    /** Get the front element. */
    int peek() {
		if (outstack.empty()){
			while (!instack.empty()){
				int tmp = instack.top();
				instack.pop();
				outstack.push(tmp);
			}
		}
		if (!outstack.empty()){
			int res = outstack.top();
			return res;
		}
		return -1;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
		return instack.empty() && outstack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
