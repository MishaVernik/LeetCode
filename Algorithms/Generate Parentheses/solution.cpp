/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
class Solution {
public:
    const string p = "()";
    void help(int n, vector<string> &v, string s){
        if (n == 0){
            stack<char> st;
            for (auto el : s){
                if (st.size() > 0 && st.top() == '(' && el == ')') 
                    st.pop();
                else 
                    st.push(el);
                }
            if (st.size() == 0)
                v.push_back(s);
        }else{
            for (auto el : p){                
                help(n-1,v,s+el);
            }
        }
            
        
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> v;
        string s = "";
        help(2*n, v, s);
        return v;
    }
};