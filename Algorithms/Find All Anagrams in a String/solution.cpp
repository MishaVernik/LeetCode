/*

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> mp(30, 0);
        for (auto el : p){
            mp[el -'a']++;
        }
        vector<int> ans;
        int lenS = s.length();
        int lenP = p.length();
        for (int i = 0; i <lenS - lenP + 1; i++){
             vector<int> tmp = mp;
            int cnt = 0;
            for (int j = i; j < i + lenP; j++){
                if (tmp[s[j] - 'a'] - 1 == 0) tmp[s[j] - 'a'] = 0;
                else
                    if (tmp[s[j] - 'a'] - 1 > 0) tmp[s[j] - 'a']--;
                    else
                    if (tmp[s[j] - 'a'] == 0) {
                        cnt = 1;
                        break;
                    }
            }
        if (cnt == 0){
            cout << i << endl;
            ans.push_back(i);
         }            
        }
        return ans;
    }
};