/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].*/
class Solution {
public:
    vector<string> a{"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void help(string s,string str, vector<string>& d, int index){
        
       // cout << str << endl;
       // cout << a[s[index] - '0'-1] << endl;
        if (index >= s.length()) {
            d.push_back(str);
            return;
        }
        for ( auto el : a[s[index] - '0' -1]) {          
            help(s, str + el, d, index + 1);
            
        }
    }    
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        string str = "";
        if (digits == "") return ans;
        help(digits, str, ans, 0);
        
        return ans;
    }
};