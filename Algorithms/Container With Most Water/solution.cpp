/**
Share
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

 



The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

 

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0;
        int r = height.size() - 1;
        // int h = 0;
        // for (int i = 0; i < height.size(); i++){
        //     h = 0;
        //     for (int j = i+1; j < height.size(); j++){
        //         h = min(height[i], height[j]);
        //         ans = max(ans, h * (j - i));
        //     }            
        // }
        while (l < r){
            ans = max(ans, (r-l)*min(height[l],height[r]));
            if (height[l] < height[r]) l++;
            else r--;
        }
        return ans;
    }
};