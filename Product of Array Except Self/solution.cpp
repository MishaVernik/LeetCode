/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int len = (int)nums.size();
        vector<int> aMin(len,1);
        vector<int> aMax(len,1);
        vector<int> ans;
        
        aMin[0] = 1;
        aMax[len-1] = 1;
        for (int i = 1; i < len;i++){
            aMin[i] = nums[i-1]*aMin[i-1];
        }
        
        for (int i = len-2; i >= 0;i--){
            aMax[i] = nums[i+1]*aMax[i+1];
        }
 
       // cout << 2;
        for (int i = 0; i < len; i++){
       //     cout << aMin[i] << " " << aMax[i] << endl;
            ans.push_back(aMin[i]*aMax[i]);
        }
        
        return ans;
    }
};