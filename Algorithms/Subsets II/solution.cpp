/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
 */
class Solution {
public:
     void deep(vector<int> nums,vector<int>& v,set<vector<int>>& st, int ind){        
        for (int i = ind; i < nums.size(); i++){                      
               v.push_back(nums[i]);
            deep(nums,v,st, i+1);                
            st.insert(v);
            v.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        ans.push_back(vector<int>());
        vector<int> v;
        set<vector<int>> st;
        deep(nums,v,st, 0);
        for (auto el : st){
            ans.push_back(el);
        }
        return ans;
    }
};  

class Solution {
public:
     void deep(vector<int> nums,vector<int>& v,vector<vector<int>>& st, int ind){        
        for (int i = ind; i < nums.size(); i++){                      
             if (i == ind || nums[i] != nums[i-1]){
                v.push_back(nums[i]);
                deep(nums,v,st, i+1);                          
                st.push_back(v);
                v.pop_back();     
            }           
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> st;
        st.push_back(vector<int>());
        vector<int> v;
       // set<vector<int>> st;
        deep(nums,v,st, 0);
        // for (auto el : st){
        //     ans.push_back(el);
        // }
        return st;
    }
};  