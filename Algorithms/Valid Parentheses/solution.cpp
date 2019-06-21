/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/
class Solution {
public:
    bool isValid(string s) {
        stack<int> stack;
        for (auto el : s){
            if (el == '{' || el == '(' || el == '[')
                stack.push(el);
            else
                if (stack.size() > 0 && ((stack.top() == '{' && el == '}') || (stack.top() == '(' && el == ')') || (stack.top() == '[' && el == ']'))){
                    stack.pop();
                }
            else 
                return false;
        }
        
        if (stack.size() == 0) return true;
        return false;
    }
};