/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/
class Solution {
public:
    bool canConstruct(string s1, string s2) {
        
        unordered_map<char,int> mp2;
        unordered_map<char,int> mp1;
        
        int len1 = (int)s1.length();
        int len2 = (int)s2.length();
        
        for (int i = 0; i < len2; i++){
            mp2[s2[i]]++;
        }
        
        int cnt = 0;
        for (int i = 0; i < len1; i++){
            if (mp2[s1[i]] > 0) mp2[s1[i]]--;
            else cnt++;
        }
        
        return !cnt;
    }
};