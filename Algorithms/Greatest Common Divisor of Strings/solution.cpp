/*
For strings S and T, we say "T divides S" if and only if S = T + ... + T  (T concatenated with itself 1 or more times)

Return the largest string X such that X divides str1 and X divides str2.

 

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""
 

Note:

1 <= str1.length <= 1000
1 <= str2.length <= 1000
str1[i] and str2[i] are English uppercase letters. 	
*/
class Solution {
private:
    int gcd(int a, int b){
        if (b == 0) return a;
        return gcd(b, a % b);
    }
public:
    string gcdOfStrings(string s1, string s2) {
        return (s1 + s2 == s2 + s1) ? s1.substr(0, gcd(s1.size(), s2.size())) : "";
    }
};