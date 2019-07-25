/*
Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

Example 1:

Input: S = "loveleetcode", C = 'e'
Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 

Note:

S string length is in [1, 10000].
C is a single character, and guaranteed to be in string S.
All letters in S and C are lowercase.
*/
class Solution {
public:
    int findShortest(vector<int> v, int i){
        int min = INT_MAX;
        for (auto el : v){
            if (abs(el - i) < min)
                min = abs(el-i);
        }
        return min;
    }
    vector<int> shortestToChar(string S, char C) {
        vector<int> v;
        vector<int> ans;
        
        for (int i = 0; i < S.length(); i++){
            if (S[i] == C)
                v.push_back(i);
        }
        
        for (int i = 0; i < S.length(); i++){
            ans.push_back(findShortest(v,i));
        }
        return ans;
    }
};