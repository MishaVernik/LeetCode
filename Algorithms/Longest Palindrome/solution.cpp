/**
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
 */
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for (auto el : s){
            mp[el]++;
        }
        int cnt = 0;
        int odd = 0;
        for (auto el : mp){
          //  cout << el.second << " " << el.first << endl;
            if (el.second % 2 == 0){
                cnt += el.second;
            }
            if (el.second % 2 == 1){
                odd = max(el.second, odd);
            }
        }
        int cnt2 = odd;
        for (auto el : mp){
            if (cnt2 == el.second){
                cnt2 = -1;
            }else
            if (el.second % 2 == 1 ){
                cnt += el.second - 1;
            }
        }
        
        return cnt + odd;
    }
};