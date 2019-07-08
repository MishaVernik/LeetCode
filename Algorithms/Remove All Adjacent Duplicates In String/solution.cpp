/*Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.

We repeatedly make duplicate removals on S until we no longer can.

Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.

 

Example 1:

Input: "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
 

Note:

1 <= S.length <= 20000
S consists only of English lowercase letters.
 */
class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        string s = "";
        int len = S.length();
        int i = 0;
        bool t = true;
        while (i < len){
            t= true;
            if (st.size() == 0) st.push(S[i]);
            else
                if (st.top() != S[i]){
                   st.push(S[i]);     
                }
            else 
                if (st.top() == S[i]){
                    int j = i;
                    while (i < len && S[i] == st.top()) i++;
                    if ((i-j) % 2 == 1)
                    st.pop();
                    t = false;
                }
            if (t)
            i++;
        }
        while (st.size() != 0){
            cout << st.top() ;
            s += st.top();
            st.pop();
        }
        for (int i = 0; i < s.length() / 2; i++){
            char c = s[i];
            s[i] = s[s.length() - 1 - i];
            s[s.length() - 1 - i] = c;
        }
        return s;
    }
};