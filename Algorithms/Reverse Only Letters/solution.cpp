/*
Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.

 

Example 1:

Input: "ab-cd"
Output: "dc-ba"
Example 2:

Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
 

Note:

S.length <= 100
33 <= S[i].ASCIIcode <= 122 
S doesn't contain \ or "
*/
class Solution {
public:
    bool isLetter(char c){
        if ((c >= 'a' && c <= 'z') ||(c >= 'A' && c <= 'Z'))
            return true;
        return false;
    }
    
    string reverseOnlyLetters(string S) {
        int len = S.length();
        int i = 0;
        int j = len - 1;
        while ( i <= j) {
            if (isLetter(S[i]) && isLetter(S[j])){
                swap(S[i], S[j]);
                i++;
                j--;
            }else
                if (isLetter(S[i]) && !isLetter(S[j]))
            {
                j--;
            }else
                if (!isLetter(S[i]) && isLetter(S[j]))
            {
                i++;
            }else
                if (!isLetter(S[i]) && !isLetter(S[j]))
            {
                i++;
                j--;
            }else{
                    i++;
                    j--;
                }
        }
        return S;
    }
};