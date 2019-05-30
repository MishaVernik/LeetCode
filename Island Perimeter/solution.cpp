
/*
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example:

Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16

Explanation: The perimeter is the 16 yellow stripes in the image below:
*/
class Solution {
public:
    
    int help(vector<vector<int>>& grid,pair<int,int> cord, pair<int,int> size){
        
        int ans = 0;
        if (cord.first + 1 >= size.first) ans++;
        else
        if (grid[cord.first+1][cord.second] == 0){
            ans++;
        }
        if (cord.first -1  < 0) ans++;
        else
        if (grid[cord.first-1][cord.second] == 0){
            ans++;
        }
        
        if (cord.second + 1 >= size.second) ans++;
        else
        if (grid[cord.first][cord.second+1] == 0){
           ans++; 
        }
        if (cord.second - 1 < 0) ans++;
        else
        if (grid[cord.first][cord.second-1] == 0){
            ans++;
        }      
     //   cout << "ANS: " << ans << endl;
        return ans;
    }
    
    void count(vector<vector<int>>& grid,vector<vector<bool>>& check,pair<int,int> cord, pair<int,int> size, int& sum){
        
      //  cout << cord.first << " " << cord.second << endl;
        sum += help(grid, cord,size);
        check[cord.first][cord.second] = 1;
        if(size.first > cord.first + 1 && grid[cord.first+1][cord.second] == 1 &&  check[cord.first+1][cord.second] == 0){       
     //       cout << 1 << endl;
            count(grid,check, {cord.first+1, cord.second}, size, sum);
        }
        if( 0 <= cord.first - 1 &&  grid[cord.first - 1][cord.second] == 1 &&  check[cord.first-1][cord.second] == 0){
  //   cout << 2 << endl;
            count(grid,check, {cord.first-1, cord.second}, size, sum);
        }
        if(size.second > cord.second + 1 &&  grid[cord.first][cord.second + 1] == 1 &&  check[cord.first][cord.second + 1] == 0){
      //      cout << 3 << endl;
            count(grid,check, {cord.first, cord.second + 1}, size, sum);
        }
        if(0 <= cord.second - 1 &&  grid[cord.first][cord.second - 1] == 1 &&  check[cord.first][cord.second - 1] == 0){
      //      cout << 4 << endl;
            
            count(grid,check, {cord.first, cord.second - 1}, size, sum);
        }
        
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int sum = 0;
        bool check = true;
        vector<vector<bool>> check1;
       
        pair<int,int> size = {(int)grid.size(),(int)grid[0].size() };
         for (int i = 0; i < size.first; i++){
             vector<bool> v(size.second, false);
             check1.push_back(v);
         }
        for (int i = 0; i < (int)grid.size() && check; i++){
            
            for (int j = 0;  j < (int)grid[i].size() && check; j++){
                if (grid[i][j] == 1){
                    count(grid, check1, {i,j}, size, sum);
                    check = false;
                }
            }
        }
        return sum;
    }
};