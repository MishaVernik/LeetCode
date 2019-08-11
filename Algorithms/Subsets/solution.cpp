/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
 */
class Solution {
public:
    void deep(vector<int> nums,vector<int>& v,vector<vector<int>>& ans, int ind){        
        for (int i = ind; i < nums.size(); i++){                      
            v.push_back(nums[i]);
            deep(nums,v,ans, i+1);                
            ans.push_back(v);
            v.pop_back();
        }
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back(vector<int>());
        vector<int> v;
        deep(nums,v,ans, 0);
        return ans;
    }
};