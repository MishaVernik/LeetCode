/**
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
 */
class Solution {
public:
    void checkIfEdge(vector<vector<char>>& board,vector<vector<bool>>& visited, vector<pair<int,int>>& v, int x, int y, bool& ans){
        visited[x][y] = true;     
        v.push_back({x,y});
        if (x + 1 == board.size() && board[x][y] == 'O') ans = true;else
        if (y + 1 == board[0].size() && board[x][y] == 'O') ans = true;else
        if (y - 1 < 0 && board[x][y] == 'O') ans = true;else
        if (x - 1 < 0 && board[x][y] == 'O') ans = true;
        
        if (x + 1 < board.size() && board[x+1][y] == 'O' &&  visited[x+1][y] == false) checkIfEdge(board,  visited,v,x + 1, y,ans);              
        if (x - 1 >= 0 && board[x-1][y] == 'O'  && visited[x-1][y] == false)  checkIfEdge(board, visited, v,x - 1, y,ans);               
        if (y + 1 < board[0].size() && board[x][y+1] == 'O'  && visited[x][y+1] == false)  checkIfEdge(board, visited,v, x, y + 1,ans);
        if (y - 1 >= 0 && board[x][y-1] == 'O'  && visited[x][y-1] == false)  checkIfEdge(board, visited,v, x , y - 1, ans);      
        // if ( x == 12) cout << "\n" << ans << " -----> " << x <<  " "<< y <<  endl;
        // if (!ans) board[x][y] = 'X';
    }
    
    void brush(vector<vector<char>>& board, int x , int y) {
        board[x][y] = 'X';
        
        if (x + 1 < board.size() && board[x+1][y] == 'O')    brush(board, x + 1, y);              
        if (x - 1 >= 0 && board[x-1][y] == 'O')              brush(board, x - 1, y);               
        if (y + 1 < board[0].size() && board[x][y+1] == 'O')  brush(board,x, y + 1);                
        if (y - 1 >= 0 && board[x][y-1] == 'O' )              brush(board,x , y - 1);        
    }
    
    template<typename T>
    void print(vector<vector<T>> v){
        cout << endl;
        for (int i = 0; i < v.size(); i++){
            for (int j = 0; j < v[0].size(); j++)
                cout << v[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
  
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) return;// print<char>(board);
      //  cout << board.size();
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), 0));
        vector<pair<int,int>> v1;
        for (int i = 0; i < board.size(); i++){
            
            for (int j = 0; j < board[0].size(); j++){
                bool t = false;   
              //  if (i == 12)   print<bool>(visited),  print<char>(board);
                if (visited[i][j] == false && board[i][j] == 'O'){                 
                  //  cout << i << " HM " << j << endl;
                     v1.clear();
                    checkIfEdge(board,visited,v1, i, j, t);
                    if (!t) {
                        for (auto el : v1)
                            board[el.first][el.second] = 'X';
                    }
                   //  if (!t){
                   // //     cout << i << " BRUSH " << j << endl;
                   //    //  brush(board,i,j);
                   //  }   
                   //  
                }
            }
            
        }
      
    }
};