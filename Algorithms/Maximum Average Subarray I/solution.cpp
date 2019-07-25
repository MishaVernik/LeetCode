/*
Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

Example 1:

Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
 

Note:

1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].
 
*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long sum = 0;
        int iS = 0;
        int iE = k;
        double maxProduct = 0;
        for (int i = 0 ; i  < k; i++)
            sum += nums[i];
        maxProduct = (double)sum/k;
        while (iE < nums.size()){
            if ((double)sum/k > maxProduct)
                maxProduct = (double)sum/k;
            sum -= nums[iS];
            sum += nums[iE];
            iS++;
            iE++;
        }
        return max(maxProduct, (double)sum/k);
    }
};