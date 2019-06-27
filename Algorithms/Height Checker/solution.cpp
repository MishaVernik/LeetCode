/*
Students are asked to stand in non-decreasing order of heights for an annual photo.

Return the minimum number of students not standing in the right positions.  (This is the number of students that must move in order for all students to be standing in non-decreasing order of height.)

 

Example 1:

Input: [1,1,4,2,1,3]
Output: 3
Explanation: 
Students with heights 4, 3 and the last 1 are not standing in the right positions.
 

Note:

1 <= heights.length <= 100
1 <= heights[i] <= 100
*/
class Solution {
public:
    int heightChecker(vector<int>& h) {
        vector<int> t = h;
        sort(t.begin(), t.end());
        int cnt = 0;
        for (int i = 0; i < t.size(); i++){
            if (t[i] != h[i])
                cnt++;
        }
        if (cnt - 1 < 0) return 0;
        return cnt;
    }
};