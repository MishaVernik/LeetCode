/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/
class MinStack {
    private:
    stack<int> mainStack;
    stack<int> minStack;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
      //  cout << x << endl;
        mainStack.push(x);
        if (minStack.size() == 0)
            minStack.push(x);
        else{
            if (minStack.top() >= x){
                minStack.push(x);
            }else{
                vector<int> v;
                while (minStack.size() > 0 ){                                 
                    if (minStack.top() < x)
                        v.push_back((int)minStack.top()), minStack.pop();     
                    else{
                        minStack.push(x);
                        break;
                    }
                        
                }
                for (int i = (int)v.size() - 1; i >= 0; i--){
                    minStack.push(v[i]);
                }
    
            }
        }            
    }
    
    void pop() {
        
        int val = mainStack.top();
       // cout << "pop " << val << endl;
        mainStack.pop();
        vector<int> v;
        while (minStack.size() > 0 ){            
            if (minStack.top() == val){
                minStack.pop();
                break;
            }
            if (minStack.size() > 0)
                v.push_back((int)minStack.top()), minStack.pop();          
        }
         for (int i = (int)v.size() - 1; i >= 0; i--){
                    minStack.push(v[i]);
         }
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
       // cout << "MIN " << minStack.top() << endl;
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */