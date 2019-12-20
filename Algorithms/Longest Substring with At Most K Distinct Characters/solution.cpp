/**
Given a string, find the length of the longest substring T that contains at most k distinct characters.

Example 1:

Input: s = "eceba", k = 2
Output: 3
Explanation: T is "ece" which its length is 3.
Example 2:

Input: s = "aa", k = 1
Output: 2
Explanation: T is "aa" which its length is 2.
 */
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        map<char, int> mp;
        int i = 0;
        int ans = 0;
        int j = 0;
         while (i < s.length()){
            if (mp.size() <= k){
                mp[s[i]]++;
                int sum = 0;
                for (auto el : mp){
                    sum += el.second;
                }
                if (mp.size() <= k)
                    ans = max(ans, sum);
                i++;
            }else{
                if (mp[s[j]] > 1) mp[s[j]]--;
                else mp.erase(s[j]);
                j++;
            }
        }
        return ans;
    }
};