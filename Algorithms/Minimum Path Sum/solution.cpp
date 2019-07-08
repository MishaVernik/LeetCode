/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 
*/
class Solution {
public:
  
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 1 && grid[0].size() == 1)
            return grid[0][0];
        vector<vector<int>> extr;
        for (int i = 0; i < grid.size(); i++){
            extr.push_back(vector<int>(grid[0].size(), 0));
        }
        int sum = 0;
        for (int i = 0; i < grid[0].size(); i++){
            sum += grid[0][i];
            extr[0][i] += sum;            
        }
        sum = 0;
        for (int i = 0; i < grid.size(); i++){
            sum += grid[i][0];
            extr[i][0] += sum;            
        }
        for (int i = 1; i < grid.size(); i++){
            for (int j = 1; j < grid[0].size(); j++){
                extr[i][j] = min(extr[i-1][j], extr[i][j-1]) + grid[i][j];
            }
        }
        
        return extr[grid.size()-1][grid[0].size()-1];
    }
};