/**
Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:

Input:  [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
Example 2:

Input:  [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
 */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int i = 0;
        while (i < nums.size()){
            int j = i;
            while (j +1 < nums.size() && nums[j]+1 == nums[j+1]) j++;
            if (j - i == 0){
              //   cout << nums[i] << endl;
                ans.push_back(to_string(nums[j]));
            }else{
               // cout << nums[i] << " " << nums[j-1]<< endl;
                ans.push_back(to_string(nums[i]) + "->"+to_string(nums[j]));
            }
            i = j + 1;
        }
        return ans;
    }
};