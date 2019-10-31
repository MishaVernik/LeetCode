/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/
class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        vector<pair<char, int>> v;
        string ans = "";
        for (auto el : s) mp[el]++;
        for (auto el : mp){
            v.push_back({el.first, el.second});
        }
        sort(v.begin(), v.end(), [](auto& l, auto& r){
            return l.second > r.second;
        });
        for (auto el : v){
            for (int i = 0; i < el.second; i++)
                ans += el.first;
        }
            //cout << el.first << "";
        //cout << endl;
        return ans;
    }
};