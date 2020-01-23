/*

Given an array of strings arr. String s is a concatenation of a sub-sequence of arr which have unique characters.

Return the maximum possible length of s.

 

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All possible concatenations are "","un","iq","ue","uniq" and "ique".
Maximum length is 4.
Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible solutions are "chaers" and "acters".
Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
 

Constraints:

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lower case English letters.
*/
class Solution {
private:
    bool check(string s1, string s2){
        vector<int> v(29,0);
        for (auto el : s1){
            if (v[el-'a'] > 0) return false;
            v[el-'a']++;
        } 
        for (auto el : s2){ 
            
            if (v[el-'a'] > 0 || v[el-'a'] < 0) return false;
            v[el-'a']--;
        }
    //    for (int i = 0; i < 27; i++) if (v[i] > 0) return false;
        return true;
    }
public:
    
    int maxLength(vector<string>& arr) {
        /*
            un iq ue 
            
            un + iq +
            un + ue -
            iq + ue +
            
            uniq + ue
            
        s intersect s1 = 0 
        s = s + s1;
        */
        queue<pair<string,int>> q;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++){           
            if (check(arr[i], "")){
               // cout << arr[i] << endl;
                q.push({arr[i], i});
                ans = max(ans,(int) arr[i].length());
            }
                
        }
            
        while (!q.empty()){
            int n = q.size();
            for (int i = 0; i < n; i++){
                auto p = q.front();
                q.pop();
                for (int j = p.second + 1; j < arr.size(); j++){
                   // cout << p.first << " " << arr[j];
                  if (check(p.first, arr[j])){
                     // cout << "1";
                      ans = max(ans, (int) p.first.length() +(int) arr[j].length());
                      q.push({p.first + arr[j], j});
                  }  
                }
            }
        }        
        return ans;
    }
};