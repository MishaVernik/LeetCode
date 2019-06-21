/*

Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:

Input: [1,2,3]
Output: 6
 

Example 2:

Input: [1,2,3,4]
Output: 24
 

Note:

The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        if ((int)nums.size() < 3){
            long long m = 1;
            for (int i = 0 ;i < nums.size(); i++){
                m *= nums[i];
            }
            return m;
        } 
        
        sort(nums.begin(), nums.end());
        long long m1 = nums[0]*nums[1]*nums[2];
        long long m2 = nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
        long long m3 = nums[0]*nums[nums.size()-1]*nums[nums.size()-2];
        long long m4 = nums[0]*nums[nums.size()-1]*nums[1];
        return max(max(m1,m2),max(m3,m4));
    }
};