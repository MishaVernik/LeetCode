/*
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

Example: 

Given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4 	
*/
class Solution {
private:
    #define INF 2147483647
    bool check(int x, int y, int lenX, int lenY){
        if (x < 0 || x >= lenX  || y < 0 || y >= lenY) return false;
        return true;
    }
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
     int dist = 0;
        queue<pair<int,pair<int, int>>> q;
        for (int i = 0; i < rooms.size(); i++){
            for (int j = 0; j < rooms[i].size(); j++){
                if (rooms[i][j] == 0){
                    q.push({dist, {i,j}});
                }
            }
        }
        
      
        vector<int> c_x = {-1,0,1,0};
        vector<int> c_y = {0,-1,0,1};
        while (!q.empty()){
            int n = q.size();
            for (int i = 0; i < n; i++){
                auto p = q.front();
                q.pop();
                for (int c = 0; c < 4; c++){
                    int newX = p.second.first + c_x[c];
                    int newY = p.second.second + c_y[c];
                    if (check(newX,newY,rooms.size(), rooms[0].size()) && rooms[newX][newY] != -1){
                        if (rooms[newX][newY] == INF){
                            q.push({p.first + 1, {newX, newY}});
                            rooms[newX][newY] = p.first + 1;
                        }else if (rooms[newX][newY] > p.first + 1) {
                            q.push({p.first + 1, {newX, newY}});
                            rooms[newX][newY] = p.first + 1;
                        }
                    }
                }
            }
        }
    }
};