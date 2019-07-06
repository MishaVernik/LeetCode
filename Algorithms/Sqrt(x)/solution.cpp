/*
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
*/
class Solution {
public:
    int mySqrt(int x) {
        if (x == 1 || x == 0) return x;
        long long ans = 1;
        int x2 = x/2;
        while (ans > 0 && ans <= x2){
             if ((long long) ans*ans <= x && (long long)  (ans+1)*(ans+1) > x){
            return ans;
        }
        if (ans*ans < x && (ans+1)*(ans+1) <= x){
            ans = ans + 1;
        }else
            ans = ans - 1;
       }
        return ans;
    }
    
    
};