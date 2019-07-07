/*
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
*/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        long MIN = -2147483748;
        long m1 = MIN;
        long m2 = MIN;
        long m3 = MIN;
        for (auto el : nums){
             if(m1==el || m2==el || m3==el){
                continue;
            }
            if (el > m1){
                m3 = m2;
                m2 = m1;
                m1 = el;
            }else
                if (el > m2 || m1 == m2){
                    m3 = m2;
                    m2 = el;
                }else
                    if (el > m3 || m3 == m2){
                        m3 = el;
                    }
        }
        if (m3 == MIN && m2 == MIN && m3 == MIN) return nums[0];
        if (m3 == MIN && m2 != MIN) return m1;
        return m3;
    }
};