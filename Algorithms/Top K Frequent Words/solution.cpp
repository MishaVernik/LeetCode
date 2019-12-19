/*
Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.	Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
*/
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int K) {
        map<string, int> mp;
        hash<string> hasher;
        for (auto word : words)
            mp[word]++;
        vector<string> ans;
        vector<pair<string, int>> v;
        for (auto el : mp){
            v.push_back({el.first, el.second});
            //cout << el.first << " " << el.second << endl;
        }
        sort(v.begin(), v.end(), [](auto& l, auto& r){
            if (l.second == r.second){
                return l.first < r.first;
            }else
           return l.second > r.second; 
        });
        for (int i = 0; i < K; i++)
            ans.push_back(v[i].first);
        return ans;
    }
};