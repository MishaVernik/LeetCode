/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/
class NumMatrix {
    vector<vector<int>> sums;
 
public:
    NumMatrix(vector<vector<int>>& matrix) {
       
        sums = matrix;
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 1; j < matrix[i].size(); j++){
                sums[i][j] += sums[i][j-1];
            }
        }    
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        if (row1 > row2 ){
            swap(col1,col2);
            swap(row1,row2);
        }
        for (int j = row1; j <= row2; j++){
            if (col1 - 1 >= 0)
             sum += sums[j][col2] - sums[j][col1-1]; 
            else 
                sum += sums[j][col2]; 
        }        
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */