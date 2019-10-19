/**
A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.
 */
class Solution {
public:
    vector<int> partitionLabels(string S) {
        // SOLUTION 1
//         int pos = 0;
//         int j = 0, i = 0;
//         vector<int> v;
//         while ( pos < S.length() && j < S.length()){
//              i = j;
//              pos = S.rfind(S[i]);
//             //  cout << S[i] << endl;
//             // cout << "POS : " <<  pos << endl;
//             // cout << " i : " << i << endl;
//              while (i < pos){
//                 int found = S.rfind(S[i]);                                     
              
//                 if (found != string::npos){
//                     pos = max(pos, found);     
//                  //   cout << "NEW : " << pos << endl;
//                 }            
//                 i++;
//             }  
//             v.push_back(pos - j + 1);            
//             j = pos + 1;
           
//         }
//        return v;
        // SOLUTION 2 
        vector<int> res, pos(26, 0);  
          for (auto i = 0; i < S.size(); ++i) pos[S[i] - 'a'] = i;
          for (auto i = 0, idx = INT_MIN, last_i = 0; i < S.size(); ++i) {
            idx = max(idx, pos[S[i] - 'a']);
            if (idx == i) res.push_back(i - exchange(last_i, i + 1) + 1);
          }
          return res;
    }
};