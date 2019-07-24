/**
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).

 

Example 1:

Input: [[4,3,8,4],
        [9,5,1,9],
        [2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:
438
951
276

while this one is not:
384
519
762

In total, there is only one magic square inside the given grid.
Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
0 <= grid[i][j] <= 15
 */
class Solution {
public:
    bool isMagicSquare(vector<vector<int>> square, int curI, int curJ){
        int sum = 0;
        int arr[10] = {0,};
        for (int i = 0 ;i < 3; i++){
            for (int j  = 0 ;j < 3; j++){
                if (square[i+curI][j+curJ] <= 9 && square[i+curI][j+curJ] >= 1){
                if (arr[square[i + curI][j + curJ]] == 0) 
                    arr[square[i+curI][j+curJ]] = 1;
                else
                    return false;} else return false;
            }
        }
        for (int i = 0; i < 3; i++)
            sum += square[i+curI][0+curJ];
        // diagonals
        int leftD = 0;
        int rightD = 0;
        
        for (int i = 0; i < 3; i++){
            leftD  += square[i+curI][i+curJ]; 
            rightD += square[2-i+curI][i+curJ];
        }
        // cout << leftD << " " << rightD << endl;
        if (leftD != sum || rightD != sum) return false;
        for (int i = 0 ; i < 3; i++){        
            leftD = 0;
            rightD = 0;
            for (int j = 0; j < 3; j++){
                rightD += square[i+curI][j+curJ]; 
           //     cout << square[j+curI][i+curJ] << endl;
                leftD  += square[j+curI][i+curJ]; 
            }             
         //    cout << leftD << " " << rightD << endl;
            if (leftD != sum || rightD != sum) return false;        
        }
        return true;    
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.size() < 3) return 0;
        if (grid[0].size() < 3) return 0;        
        int ans = 0;        
        
        for (int i = 0; i  < grid.size()-2; i++){
            for (int j = 0; j < grid[i].size()-2; j++){
                
                if (isMagicSquare(grid, i, j)) ans++;
            }
        }
        return ans;
    }
    
};