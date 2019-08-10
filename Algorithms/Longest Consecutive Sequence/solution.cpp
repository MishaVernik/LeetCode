/*
Share
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        // sort(nums.begin(), nums.end());
       set<int> v(nums.begin(), nums.end());
        int ans = 1;
        int mx = 1;
        int i = 0;
        int n = 0;
        
        for (auto el : v){
            if (i == 0){
                n = el; i++;
            }else{
                if (n + 1== el) ans++, n = el;
                else 
                    mx = max(mx,ans), ans = 1, n = el;    
            }            
        }
        cout << ans;
        return max(mx,ans);
    }
};