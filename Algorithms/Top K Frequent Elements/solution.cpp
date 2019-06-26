/*
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<pair<int,int>> v;
        for (auto el: nums){
            mp[el]++;
        }
        for (auto el: mp){
           // cout << el.first << " " << el.second << endl;
            v.push_back({el.second,el.first});
        }
        sort(v.begin(), v.end(), [](auto& l, auto& r){
           return l.first > r.first; 
        });
        vector<int> ans;
        for (int i =0 ;i < k; i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};