/**
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
 */
class Solution {
public:
    bool findSmallestDiff(vector<int> arr, int k){
        if (arr.size() < 2) return false;
        sort(arr.begin(), arr.end());            
        for (int i = 1; i < arr.size(); i++){
            if (arr[i] - arr[i-1] <= k) return true;
        }
        return false;
    }    
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>> mp;
        for (int i = 0 ;i < nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        for (auto el : mp){
            if (findSmallestDiff(el.second, k)) return true;
        }
        
        return false;
    }
};