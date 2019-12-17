/*
Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a==c and b==d), or (a==d and b==c) - that is, one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].

 

Example 1:

Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1
 

Constraints:

1 <= dominoes.length <= 40000
1 <= dominoes[i][j] <= 9
*/
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>, int> mp;
        for (auto& dominoe : dominoes){
            if (dominoe[0] > dominoe[1])
                swap(dominoe[0], dominoe[1]);
        }
        for (auto el : dominoes){
            mp[el]++;
        }
        // set<vector<int>> st(dominoes.begin(), dominoes.end());
        int ans = 0;
        for (auto el : mp){
            ans += (el.second * (el.second - 1) ) / 2;
        }
        return ans;
    }
};