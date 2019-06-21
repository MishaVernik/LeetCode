/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/
class Solution {
public:
    
    bool help(unordered_map<char,int> mp, string s, int i, int len1){
        int cnt  = 0;
        for (int j = i; j < i + len1; j++){
         //   cout << s[j];
            if (mp[s[j]] > 0) mp[s[j]]--;
            else cnt++;
        }
       // cout << endl;
        return cnt;
    }
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;
        for (auto el : s1){
            mp[el]++;
        }
        int len1 = (int)s1.length();
        int len2 = (int)s2.length();
        if (len1 == 0 || len2 == 0) return false;
        if (len1 > len2) return false;
        long hashS1 = 0;
        long hashS2 = 0;
        int counter2 = 0;
        for (int j = 0; j < len1; j++){
            hashS1 += ((s1[j] - 'a') + 3) * 5;
            hashS2 += ((s2[j] - 'a') + 3) * 5; 
        }
     //   cout << hashS1 << endl;
    //   cout << hashS2 << endl;
        for (int j = len1; j <= len2; j++){
            if (hashS1 == hashS2){
            //    cout << s2[j-len1] << endl;
                if (!help(mp, s2, j-len1, len1)){
                return true;
             }
            }
            
            //cout << "-- " << s2[j-len1] << " " << ((s2[j-len1] - 'a') + 3) * 5 << endl;
           // cout << "-- > " << s2[j] << " " << ((s2[j] - 'a') + 3) * 5 << endl;
           // cout << " __ " << s2.substr(j-len1, len1) << endl;
            hashS2 = hashS2 - ((s2[j-len1] - 'a') + 3) * 5 + ((s2[j] - 'a') + 3) * 5;
           // cout << hashS2 << endl;
           }                
        
        return false;
    }
};