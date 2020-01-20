/*
You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.

 

Example 1:

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: 
The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
Example 2:

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: 
The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
 

Note:

1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
All strings contain lowercase English letters only.
*/
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
       
        int ans = 0;
        unordered_map<int, int> mp;
        vector<int> arr(28, 0);
        for (auto el : chars) mp[el]++;
        
        for (auto word : words){
            unordered_map<int, int> tmp = mp;
            bool c = true;
            for (auto el : word){
                if (tmp.find(el) == tmp.end()){
                    c = false;
                    break;
                }else {
                    if (tmp[el] - 1 > 0) tmp[el]--;
                    else if (tmp[el] - 1 == 0)
                        tmp.erase(el);
                    else {
                        c = false;
                        break;
                    }
                }
            }
            if (c) ans += word.length();
        }
        return ans;
    }
};