/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/
class Solution {
public:
    string reverse(string s){
        
        int len = (int)s.length();
        for (int i = 0; i < (int)s.length()/2; i++){
            char c = s[i];
            s[i] = s[len-1-i];
            s[len-1-i] = c;
        }
        return move(s);
    }
    
    string reverseWords(string s) {    
        string s1 = "";
        int len = (int)s.length();
         size_t pos;
	 
 
        string token;
        string delimiter = " "; 
            pos = 0;
            while ((pos = s.find(delimiter)) != std::string::npos) {
                token = reverse(s.substr(0, pos));   
               // cout << token << endl;
                s1 +=token + " ";      
                
                s.erase(0, pos + delimiter.length());
            }   

        return s1 + reverse(s.substr(0, pos)); 
    }
};