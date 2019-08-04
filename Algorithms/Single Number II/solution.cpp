/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (auto el : nums){
            if (mp[el] + 1 == 3) mp.erase(el);
            else
                mp[el]++;
        }
        int ans = 0;
        for (auto el : mp)
            ans = el.first;
        
        return ans;
    }
};