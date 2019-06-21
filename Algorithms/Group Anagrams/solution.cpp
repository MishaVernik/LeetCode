/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/
class Solution {
public:
    int LETTERS[30] {1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,57,59,61,67,71,73,79,83,87,89,91,97,101,};
  long long hash(string s){
      
        long long a = 1;
        for (auto el : s){
            a = (a*LETTERS[el - 'a'])%100000000007;
        }
      return a;
  }
    bool compare(string s1, string s2){        
        if (s1.length() != s2.length()) return false;
         int *arr1 = new int[26]{0,};
         int *arr2 = new int[26]{0,};
        for (int i = 0; i < s1.length();++i){
            arr1[s1[i] - 'a']++;
            arr2[s2[i] - 'a']++;
        }
        for (int i = 0; i <26; i++){
            if (arr1[i] != arr2[i]){
                
                return false;
            }
                
        }
        delete[] arr1;
        delete[] arr2;
        return true;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {         
        vector<pair<long long, vector<string>>> ans;              
        long long hash_t = 0;
        for (auto str : strs){
            int *arr = new int[26]{0,};
            for (auto el : str){
                arr[el-'a']++;
            }
            if (ans.size() == 0){
                vector<string> v;
                v.push_back(str);
                hash_t = hash(str);
                ans.push_back({hash_t, v});
            }else{
                bool t = false;
                hash_t = hash(str);
                for (auto & v : ans){
                    if (v.first == hash_t && compare(v.second[0], str)){                        
                        v.second.push_back(str);                        
                        t = true;
                        break;
                    }
                }
                
                if (!t){
                     vector<string> v;
                    hash_t = hash(str);
                    v.push_back(str);
                    ans.push_back({hash_t,v});
                }
            }
                delete[] arr;
        }
         
        vector<vector<string>> res;
        for (auto str : ans){
            res.push_back(str.second);
        }
        return res;
    }
};