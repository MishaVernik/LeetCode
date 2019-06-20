/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
//         int n = (int)nums.size();
//         long sqrSum = (n*(n+1)*(2*n+1))/6;
//         long sum = (n*(n+1))/2;
        
//         for (auto el: nums){
//             sqrSum -= el*el;
//             sum -= el;
//         }
//         if (sqrSum < 0) return n;
        
//         return (sqrSum / sum) - n;
        
//         int slow = 0;
//         int fast = 0;
//         int finder = 0;

//         while (true)
//         {
//             slow = nums[slow];
//             fast = nums[nums[fast]];

//             if (slow == fast)
//                 break;
//         }
//         while (true)
//         {
//             slow = nums[slow];
//             finder = nums[finder];
//             if (slow == finder)
//                 return slow;
//         }
        unordered_map<int,int> mp;
        for (auto el: nums){
            if (mp[el] > 0) return el;
            mp[el]++;
        }
        
        return 0;
    }
};