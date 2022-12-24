/*
Implement a first in first out (FIFO) queue using only two stacks. 
The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.

Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. 
You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
*/

class MyQueue {
private:
        stack<int> main,q;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        // this->p=x;
        this->main.push(x);
    }
    
    int pop() {
        if(q.empty() && main.empty())return -1;
        if(q.empty()){
            while(!main.empty()){
                this->q.push(main.top());
                main.pop();
            }
        }
        int ans = q.top();
        this->q.pop();
        return ans;
    }
    
    int peek() {
        if(this->q.empty() && this->main.empty())return -1;
        if(q.empty()){
            while(!main.empty()){
                q.push(main.top());
                main.pop();
            }
        }
        int ans = q.top();
        return ans;
    }
    
    bool empty() {
        if(q.empty() && main.empty())return true;
        return false;
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
