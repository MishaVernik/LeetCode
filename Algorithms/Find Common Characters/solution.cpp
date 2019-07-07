/*
Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.

 

Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]
 

Note:

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] is a lowercase letter
Accepted
*/
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int len = A.size();
        vector<string> ans;
        int cnt = 0;
        int** mp = new int*[len];
        for(int i = 0; i < len; ++i)
            mp[i] = new int[27]{0,};
        
        for (int i = 0; i < len; i++){
            for (auto e : A[i]){
                mp[i][e-'a']++;
            }
        }
        for (int i = 0; i < len; i++){
            for (int j = 0; j < 27; j++){
                cout << mp[i][j] <<  " ";
            }
            cout << endl;
        }
        for (int i = 0; i < 27; i++){
            int mx = INT_MAX;
            for (int j = 0; j < len; j++){
                if (mp[j][i] < mx) 
                    mx = mp[j][i];
            }
           // cout <<  mx << endl;
            if (mx > 0){
                string s;
               // cout << "YESH";
               // cout << i << endl;
                s += static_cast<char>(i+(int)'a');
                cout << s << endl;
                for (int j = 0; j < mx; j++){
                    ans.push_back(s);
                 }
            }
        }
        return ans;
    }
};