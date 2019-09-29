/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

 */
const int ZERO = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
//         int sum = 0;
//         for (int i = 0; i < nums.size(); i++){
//             sum = nums[i];
//             if (sum == k){ ans++; }
//             for (int j = i + 1; j < nums.size(); j++){
//                 if (sum + nums[j] == k){
//                     sum += nums[j];
             
//                     ans++;                  
//                 } else sum += nums[j];
//             }
//         }
        unordered_map<int,int> mp;
        mp[0]++;
        // sum[i,j] = sum[0,j] - sum[0, i - 1];
        // 1 4 1 1 4 1
        // sum[1,3] = sum[0,3] - sum[0, 0]
        // sum[0,3] = 1 + 4 + 1 + 1
        // sum[0,0] = 1
        // sum[1,3] = (sum[0,0] + sum[0,1] + sum[0,2] + sum[0,3]) - (sum[0,0]); 
        int sum = 0;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if (mp[sum - k] > 0) ans+=mp[sum - k];
            mp[sum]++;
        }
        return ans;
    }
};