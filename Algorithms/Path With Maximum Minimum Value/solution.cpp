/*
Given a matrix of integers A with R rows and C columns, find the maximum score of a path starting at [0,0] and ending at [R-1,C-1].

The score of a path is the minimum value in that path.  For example, the value of the path 8 →  4 →  5 →  9 is 4.

A path moves some number of times from one visited cell to any neighbouring unvisited cell in one of the 4 cardinal directions (north, east, west, south).

 

Example 1:



Input: [[5,4,5],[1,2,6],[7,4,6]]
Output: 4
Explanation: 
The path with the maximum score is highlighted in yellow. 
Example 2:



Input: [[2,2,1,2,2,2],[1,2,2,2,1,2]]
Output: 2
Example 3:



Input: [[3,4,6,3,4],[0,2,1,1,7],[8,8,3,2,7],[3,2,4,9,8],[4,1,2,0,0],[4,6,5,4,3]]
Output: 3
 

Note:

1 <= R, C <= 100
0 <= A[i][j] <= 10^9
*/
class Solution {
private:
    bool isSafe(int x,int y, int xSize, int ySize){
        if (x < 0 || x>= xSize || y < 0 || y >= ySize)
            return false;
        return true;
    }
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        vector<int> dir = {0, 1, 0, -1, 0};
        priority_queue<tuple<int,int,int>> pq;
        int ans = A[0][0];
        pq.push({A[0][0], 0,0});
        A[0][0] = -1; // visited
        while (!pq.empty()){
            int n = pq.size();
            for (int i = 0; i < n; i++){
                auto [val, x, y] = pq.top();
                pq.pop();
                ans = min(ans, val);
                if (x == A.size() - 1 && y == A[0].size() -1)
                    return ans;
                for (int j = 0; j < 4; j++){
                    int newX = dir[j] + x;
                    int newY = dir[j + 1] + y;
                    if (isSafe(newX,newY, A.size(), A[0].size())){
                        if (A[newX][newY] != -1){
                            pq.push({A[newX][newY], newX, newY});
                            A[newX][newY] = -1;
                        }
                    }
                    
                }
            }
        }
        
        return -1;
    }
};