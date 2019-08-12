/**
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
 */
class Solution {
public:
    void deep(vector<int> nums, vector<int>& v, unordered_map<int, bool>& marked, int ind, int& ans){
        marked[nums[ind]] = true;
        v.push_back(ind);
        ans = max(ans, (int)v.size());
        for (int i = ind+1; i < nums.size(); i++){     
            
            if (nums[i] > nums[v.back()]) {
                    deep(nums,v,marked,i, ans);   
                    // for (auto el : v) cout << el << " ";
                    // cout << endl;
                    v.pop_back();
            }
        }
       
    }
    int lengthOfLIS(vector<int>& nums) {
//         vector<int> v;
//         unordered_map<int, bool> mp;
//         int ans = 0;        
//         for (int i = 0; i < nums.size() && mp.size() != nums.size(); i++){
//             // for (auto el : mp){
//             //     cout << el.first << " ";
//             // }cout << endl;
//             if (mp.find(nums[i]) == mp.end()){
//                 deep(nums,v,mp, i, ans);
//                 v.pop_back();               
//             }            
            
//         }
//         return ans;
        if (nums.size() == 0) return 0;
        int maxVal = 0;
        int maxAns = 1;
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++){
            maxVal = 0;
            for (int j = 0; j < i; j++){
                if (nums[i] > nums[j])
                    maxVal = max(maxVal, dp[j]);
            }
            dp[i] = maxVal + 1;
            maxAns = max(dp[i], maxAns);
        }
        return maxAns;
    }
};