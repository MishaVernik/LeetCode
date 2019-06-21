/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i = 0;
        while( i < (int)nums.size()){
            //  cout << nums[i] << " " << nums[nums[i]-1] << endl;
            if (nums[i] != nums[nums[i]-1]){                
                swap(nums[i], nums[nums[i]-1]);
            }else 
                i++;           
          
        }
        vector<int> ans;
        for (int i = 0; i < (int)nums.size(); i++){
            if (nums[i] != i+1){
                ans.push_back(i+1);                
            }
        }
        return ans;
    }
};