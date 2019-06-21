/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/
class Solution {
public:
    /*
        s = "anagram", t = "nagaram"
        map<char, int> mp;
        unordered_map<char, int>
    */
    bool isAnagram(string s, string t) {
            
        unordered_map<char, int> mp;
        for (auto el : s){
            mp[el]++;
        }
        
        int cnt = 0;
        for (auto el : t){
            if (mp[el] > 0){
                if (mp[el] - 1 > 0) mp[el]--;
                else mp.erase(el);    
            }else cnt++;        
        }
       // cout << mp.size();
        if (cnt > 0 || (int)mp.size() > 0) return false;
        return true;
    }
};