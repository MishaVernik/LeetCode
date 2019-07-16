/*
Suppose you are given the following code:

class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}
The same instance of FooBar will be passed to two different threads. Thread A will call foo() while thread B will call bar(). Modify the given program to output "foobar" n times.

 

Example 1:

Input: n = 1
Output: "foobar"
Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar(). "foobar" is being output 1 time.
Example 2:

Input: n = 2
Output: "foobarfoobar"
Explanation: "foobar" is being output 2 times.
*/
class FooBar {
private:
    int n;
    int tmp;
    mutex m1,m2;
public:
    FooBar(int n) {
        this->n = n;
        m1.lock();
        m2.lock();
        tmp = 1;
    }

    void foo(function<void()> printFoo) {
        
        m1.unlock();
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
            //while (tmp == 2) {}
            m1.lock();
            printFoo();
           
            m2.unlock();
            
            // tmp = 2;
             
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
        	// printBar() outputs "bar". Do not change or remove this line.
            // while (tmp == 1){}
            m2.lock();
            printBar();
           
            m1.unlock();
            // tmp = 1;
         }
    }
};