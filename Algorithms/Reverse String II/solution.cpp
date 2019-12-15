/*
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]
Accepted
73,077
Submissions
156,332
*/
class Solution {
private:
    void reverseS(string& s,int i, int k){
        int sz = i + k;
        if (i + k >= s.size()) sz = s.size();
        reverse(s.begin() + i, s.begin() + sz);
    }
public:
    string reverseStr(string s, int k) {
        
        for (int i = 0; i < s.size(); i+= 2*k){
            reverseS(s, i,k);            
        }

        //cout << s;
        return s;
    }
};