/*
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Example:

MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
 

Accepted
97,486
Submissions
142,558
 
*/
class MovingAverage {
private:
    deque<int> dq;
    int sz;
    int counter;
    int sum;
    bool filled;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sz = size;
        counter = 0;
        sum = 0;
        filled = false;
    }
    
    double next(int val) {
       
        if (counter == sz){
            filled = true;
            sum -= dq.front();
            dq.pop_front();            
        }
       
        if (!filled)
            counter++;
        
        dq.push_back(val); 
        sum += val;
        return static_cast<double>(sum) / static_cast<double>(counter);
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */