/*Design a max stack that supports push, pop, top, peekMax and popMax.

push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
Example 1:
MaxStack stack = new MaxStack();
stack.push(5); 
stack.push(1);
stack.push(5);
stack.top(); -> 5
stack.popMax(); -> 5
stack.top(); -> 1
stack.peekMax(); -> 5
stack.pop(); -> 1
stack.top(); -> 5
Note:
-1e7 <= x <= 1e7
Number of operations won't exceed 10000.
The last four operations won't be called when stack is empty.
*/
// SOLUTION 2
class MaxStack {
private:
    stack<int> st1;
    stack<int> st2;
    set<int> s;
    map<int,int> mp;
    void deleteInStack(int x){
        
        if (st1.empty()) return;
        auto r = st1.top();
        st1.pop();
        if (r == x){
            return;
        }else 
            deleteInStack(x);
        
        
        st1.push(r);
    }    
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
       // mp[x]++;
        st1.push(x);
        if (st2.empty()) {
            st2.push(x);
            return;
        }
        if (st2.top() < x) st2.push(x);
        else st2.push(st2.top());
        // s.insert(x);
        // if (st2.size() == 0) st2.push(x);
        // else
        //     if (x > st2.top()) st2.push(x);
        // else st2.push(st2.top());
    }
    
    int pop() {
        auto x = st1.top();
        st1.pop();
        st2.pop();
        return x;
    }
    
    int top() {
        return st1.top();
    }
    
    int peekMax() {
        return st2.top();//*s.rbegin();
    }
    
    int popMax() {
        
        int x = peekMax();
        stack<int> buf;
        while (st1.top() != x){
            buf.push(pop());
        }
        pop();
        while (!buf.empty()){
            push(buf.top());
            buf.pop();
        }
        return x;
//         auto x = *s.rbegin();
       
//         deleteInStack(x);
//         if (mp[x] > 1) mp[x]--;
//         else {
//             mp.erase(x);
//              s.erase(x);
//         }
 
//         return x;
        
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
// SOLUTION 1
class MaxStack {
private:
    stack<int> st1;
    //stack<int> st2;
    set<int> s;
    map<int,int> mp;
    void deleteInStack(int x){
        
        if (st1.empty()) return;
        auto r = st1.top();
        st1.pop();
        if (r == x){
            return;
        }else 
            deleteInStack(x);
        
        
        st1.push(r);
    }    
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        mp[x]++;
        st1.push(x);
        s.insert(x);
        // if (st2.size() == 0) st2.push(x);
        // else
        //     if (x > st2.top()) st2.push(x);
        // else st2.push(st2.top());
    }
    
    int pop() {
        auto x = st1.top();
        st1.pop();
        if (mp[x] > 1) mp[x]--;
        else{
            mp.erase(x);
            s.erase(x);
        }
        return x;
    }
    
    int top() {
        return st1.top();
    }
    
    int peekMax() {
        return *s.rbegin();
    }
    
    int popMax() {
        
        auto x = *s.rbegin();
       
        deleteInStack(x);
        if (mp[x] > 1) mp[x]--;
        else {
            mp.erase(x);
             s.erase(x);
        }
 
        return x;
        
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */