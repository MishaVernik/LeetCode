/**
In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

 

Example 1:



Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] is only 0, 1, or 2.
Accepted
31,153
Submissions
66,963
 */
class Solution {
private:
    
    bool check(int x, int y, int xSize, int ySize){
        if (x < 0 || y < 0 || xSize <= x || ySize <= y)
            return false;
        return true;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.size() < 1) return 0;
        queue<pair<int,int>> q;
        int oranges = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[i].size(); j++){
                if (grid[i][j] == 2){
                    q.push({i,j});
                }
                if (grid[i][j] == 1){
                    oranges++;
                }
            }
        }
        int minutes = 0;
        int xSize = grid.size();
        int ySize = grid[0].size();
        vector<int> directions = {0, 1, 0, -1, 0};
        while (!q.empty()){
            int n = q.size();
            for (int i = 0; i < n; i++){                       
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int j = 0; j < directions.size() - 1; j++){
                    int newX = x + directions[j];
                    int newY = y + directions[j + 1];
                  //  cout << newX << " " << newY << " " << check(newX,newY,xSize, ySize) << endl;
                    if (check(newX,newY,xSize, ySize)){
                        if (grid[newX][newY] == 1){                         
                            grid[newX][newY] = 2;
                            q.push({newX, newY});
                            oranges--;   
                        }
                    }
                }    
            }
            //cout << "=====================\n";
            if (q.empty()){
                 if (oranges > 0) return -1;
                 return minutes;
            }
                                 
            minutes++;
        }
        //cout << oranges;
        if (oranges > 0) return -1;
        return minutes;
    }
};