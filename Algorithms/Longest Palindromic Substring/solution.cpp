/**
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
Accepted
740,281
Submissions
2,603,833
 */
class Solution {
private: 
    int stringMiddle(string s, int left, int right){
        if (s.length() < 1 || left > right) return 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left - 1;
    }
public:
    string longestPalindrome(string s) {
        if (s.length() < 1) return "";
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.length(); i++){
            int len1 = stringMiddle(s, i, i);
            int len2 = stringMiddle(s, i, i + 1);
            int len = max(len1,len2);
            if (len > end - start){
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }        
       // cout << start << "  " << end;
        return s.substr(start, end - start + 1);
    }
    
    
};