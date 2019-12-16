/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
Accepted
294,003
Submissions
678,763
*/
const auto ZERO = [](){  
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    return 0;
};

class Solution {
private:
    void permutate(vector<vector<int>>& ans, vector<int> arr, int ind){
        if (ind + 1 >= arr.size()) ans.push_back(arr);else
        for (int i = ind; i < arr.size(); i++){
            if (i == ind || arr[i] != arr[ind]){                
                swap(arr[i], arr[ind]);
                permutate(ans, arr, ind + 1);              
            }            
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        permutate(result, nums, 0);    
//         for (auto st : ans)
//             result.push_back(st);
        
        return result;
    }
};