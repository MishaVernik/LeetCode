/*
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:

Input:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Output:
[[0,0,0],
 [0,1,0],
 [0,0,0]]
Example 2:

Input:
[[0,0,0],
 [0,1,0],
 [1,1,1]]

Output:
[[0,0,0],
 [0,1,0],
 [1,2,1]]
 

Note:

The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
*/
 class Solution {
private:
    bool isSafe(int x, int y, int xSize, int ySize){
        if (x < 0 || x >= xSize || y < 0 || y >= ySize){
            return false;            
        }
        return true;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        // SOLUTION 2                   
        vector<vector<int>> ans(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));      
        // SOLUTION 1
        //         vector<vector<int>> ans(matrix.size(), vector<int>(matrix[0].size(), 0));
        queue<pair<int,int>> q;
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (matrix[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        vector<int> dir = {0,1,0,-1,0};
        while (!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            for (int i = 0; i < 4; i++){
                int x = p.first + dir[i];
                int y = p.second + dir[i + 1];
                if (isSafe(x,y,matrix.size(), matrix[0].size())){
                    if (ans[x][y] > ans[p.first][p.second] + 1){
                        ans[x][y] = ans[p.first][p.second] + 1;
                        q.push({x, y});
                    }
                }
            }
        }
        return ans;
//         
//         while (!q.empty()){
//             queue<tuple<int,int, int>> q2;
//             int dist = 0;
//             bool find = false;
//             q2.push({q.front().first, q.front().second, dist});
//             int x1 = q.front().first;
//             int y1 = q.front().second;
//             q.pop();
//             while (!q2.empty() && !find){
//                 int  n = q2.size();    
//                 for (int i = 0; i < n && !find; i++){
//                     auto [x,y,val] = q2.front();
//                     val = val + 1;
//                     q2.pop();                    
//                     for (int j = 0; j < 4 && !find; j++){
//                         int newX = x + dir[j];
//                         int newY = y + dir[j + 1];
//                         if (isSafe(newX,newY,matrix.size(), matrix[0].size())){
//                             if (matrix[newX][newY] == 0){
//                                 ans[x1][y1] = val;
//                                 find = true;                                
//                             }else{
//                                 q2.push({newX,newY, val});
//                             }
//                         }
//                     }
//                 }
//             }
//             //ans[x1][y1] = dist;
//         }
//         return ans;
    }
};