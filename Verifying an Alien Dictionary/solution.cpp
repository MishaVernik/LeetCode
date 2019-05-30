/*
In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.

 

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > 'Ø', where 'Ø' is defined as the blank character which is less than any other character (More info).
 

Note:

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are english lowercase letters.

*/

class Solution {
public:
    int compare(string s1, string s2, unordered_map<char,int> mp){
        int len1 = (int)s1.length();
        int len2 = (int)s2.length();
        int j = 0, i = 0;
        while (i < len1 && j < len2){
            // cout << mp[s1[i]] << " -6- > " << s1[i] << endl;
                 //   cout << mp[s2[j]] << " -6- > " << s2[j] << endl;
            if (mp[s1[i]] > mp[s2[j]]) return 2;
            else
                if (mp[s1[i]] < mp[s2[j]]) {
                  //  cout << mp[s1[i]] << " -- > " << s1[i] << endl;
                  //  cout << mp[s2[j]] << " -- > " << s2[j] << endl;
                    return 1;
                }
            i++;
            j++;
        }
        if (i + 1 >= len1) return 1;
        else if (j + 1 >= len2) return 2;
        
        return 0;
    }
    bool isAlienSorted(vector<string>& words, string order) {
      unordered_map<char, int> mp;
        int cnt = 1;
          for (auto el : order){
              mp[el] = cnt;
              cnt++;
          }
        for (int i = 0; i < (int)words.size(); i++){
            for (int j = i + 1; j < (int)words.size(); j++){
                if (compare(words[i], words[j], mp) == 2){
                    return false;
                }                    
            }

        }
        
        return true;
    }
};