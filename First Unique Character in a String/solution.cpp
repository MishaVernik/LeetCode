/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/
class Solution {
public:
    int firstUniqChar(string S) {
           unordered_map<char, int> mp;
        for (auto el : S){
            mp[el]++;
        }
        int res = 0;
        int i = 0;
        for (auto el : S){            
            if (mp[el] == 1) return i; 
            i++;
        }
        
        return -1;
    }
};