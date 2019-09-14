/*
Your are given an array of positive integers nums.

Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.

Example 1:
Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Note:

0 < nums.length <= 50000.
0 < nums[i] < 1000.
0 <= k < 10^6.
 */
auto __ = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    void travers(vector<int>& nums, int k, long product, int i, int &ans, bool& ch){
        if (ch) return;
        for(int j = i; j < nums.size() && !ch; j++){
            if (product * nums[j] < k){
               ans++;  
             //   cout << product * nums[j] << " "<< product << " " << nums[j] << endl;
               travers(nums,k,product*nums[j], j+1, ans,ch);   
            }else{
                ch = true;
            }                
        }
        ch = true;
    }
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // SOLUTION 1 : 2^n
//         int ans = 0;  bool ch = false;
//         for (int i =0; i < nums.size(); i++){
//           ch = false;
//             travers(nums, k, 1, i, ans, ch);    
            
//         }
//         return ans;
        // SOLUTION 2 : n ^ 2
        // int ans = 0;
        // int product = 1;
        // int i = 0;
        // int j = nums.size();
        // while (i < nums.size()){
        //     j = i;
        //     product = 1;
        //     while (j < nums.size() && product * nums[j] < k){
        //         product *= nums[j];
        //         ans++;
        //         j++;
        //     }
        //     i++;
        // }
        // return ans;
        if (k <= 1) return 0;
        int ans = 0;
        int product = 1;
        int i = 0;
        int j = 0;
        while (i < nums.size()){            
            product *= nums[i];
            while (j < nums.size() && product >= k){
                product /= nums[j];
                j++;
                //j++;                
            }
            ans += i - j + 1;
            i++;
        }
        return ans;
    }
};