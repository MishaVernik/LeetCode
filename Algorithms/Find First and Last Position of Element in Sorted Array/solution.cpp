/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1,-1};
        int l = 0;
        int r = (int)nums.size();
        int m = 0;
        while (l < r){
            m = (l + r) / 2;
          //  cout << nums[m] << endl;
            if (nums[m] == target && m > 0 && nums[m-1] != target)
                break;
            else
                if (m == 0 && nums[m] == target)
                    break;
            else if (nums[m] >= target)
                r--;
            else l++;
        }
        l = 0;
        r = (int)nums.size();
        int m1 = -1;
          while (l < r){
            m1 = (l + r) / 2;
            if (m1 <  (int)nums.size() - 1 && nums[m1] == target    && nums[m1+1] != target)
                break;
            else 
                if (nums[m1] == target && m1 == (int)nums.size()-1)
                    break;
            else if (nums[m1] <= target)
                l++;
            else r--;
        }
        cout << m << " " << m1;
        if (nums[m] != target || nums[m1] != target)
            return vector<int> {-1,-1};
        return vector<int> {m, m1};
    }
};