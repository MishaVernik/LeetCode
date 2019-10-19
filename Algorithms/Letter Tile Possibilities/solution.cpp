/**
You have a set of tiles, where each tile has one letter tiles[i] printed on it.  Return the number of possible non-empty sequences of letters you can make.

 

Example 1:

Input: "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
Example 2:

Input: "AAABBC"
Output: 188
 

Note:

1 <= tiles.length <= 7
tiles consists of uppercase English letters.
 */
class Solution {
  
    void permutate(int index, string t, int cur){      
        if (index == cur){            
            st.insert(t.substr(0, cur));
        }else        
        for (int i = index; i < t.size(); i++){                       
            swap(t[i], t[index]);
            permutate(index + 1, t, cur);
            swap(t[i], t[index]);            
        }
       
    }
    
    void count(string tiles, int i, set<string>& s){
        
    }
public:
   set<string> st; 
    int numTilePossibilities(string tiles) {
        string s = tiles;   
      
        for (int i = 0; i < s.size(); i++){
            
              permutate(0, s, i + 1);
        }        
 
        return st.size();
    }
};