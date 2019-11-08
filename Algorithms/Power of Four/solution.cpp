/**

Given an integer, write a function to determine if it is a power of two.
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true
Example 2:

Input: 5
Output: false
Follow up: Could you solve it without loops/recursion?
 */
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n-1)) == 0 && (n - 1) % 3 == 0;
       
        if (!(n > 0 && (n & (n-1)) == 0)){
            return false;
        }           
        return (n & 0x55555555) != 0;
    }
};