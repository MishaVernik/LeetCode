/**
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:

[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.
 */
class Solution {
public:
     void help(vector<vector<int>>& grid,int x, int y, int& c){
        // dfs
        grid[x][y] = 0;
        if (x - 1 >= 0 && grid[x-1][y] == 1)                  c++,help(grid, x-1,y, c);
        if (x + 1 < grid.size() && grid[x+1][y] == 1)         c++,help(grid, x+1,y, c);
        if (y - 1 >= 0 && grid[x][y-1] == 1)                  c++,help(grid, x,y-1, c);
        if (y + 1 < grid[0].size() && grid[x][y+1] == 1)      c++,help(grid, x,y+1, c);
         
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int cnt = 0;
        int mx = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1){       
                    mx = 1;
                    help(grid, i,j, mx);                    
                    cnt = max(cnt, mx);
                }
            }
        }
        return cnt;        
    }
};