/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
 
*/
const int ZERO = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);    
    return 0;
}();
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        map<int, int> mp;
        int ans = INT_MAX;
        long long sum = 0;
        int i = 0;
        int j = i;
        while (i < nums.size()){                    
            while (j < nums.size() && sum < s) {
                sum += nums[j];
                j++;
            }
           // cout << "SUM:  " << sum << endl;
          //  cout<< j << endl;
            bool t = false;
            if (sum >= s)
            ans = min(ans, j - i);
            while (i <=  j && sum >= s) {                                
                sum -= nums[i];
                t  = true; 
                i++;
                if (sum >= s) 
                    ans = min(ans, j - i);
               
            }   //     cout << "i : " << i << endl;
             // cout << "SUM 2: " << sum << endl;
            if (!t) i++;
        }
        if (ans == INT_MAX) return 0;
        return ans;
        
        /////////////////////////////////////////
        for (int i = 0; i < nums.size(); i++){            
            sum += nums[i];
            if (mp.find(sum - s) != mp.end()){
                ans = min(i - mp[sum - s],ans);                
            }                    
            mp[sum] = i;              
        }
        if (ans == INT_MAX) return 0;
        return ans;
    }
};