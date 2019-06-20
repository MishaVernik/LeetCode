/*
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701
*/
class Solution {
public:
    /*
     AA ---> A A 
     last to first
     sum += last
    */
    int titleToNumber(string s) {
        int len = (int)s.length();
        int len1 = len-1;
        unsigned int ans = 0;
        int i = 0;
        while (i < len){
             ans *= 26; 
             ans += s[i]  - 'A' + 1; 
            i++;
        }
        
        return ans;
    }
};