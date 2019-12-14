 	
/*
You are asked to cut off trees in a forest for a golf event. The forest is represented as a non-negative 2D map, in this map:

0 represents the obstacle can't be reached.
1 represents the ground can be walked through.
The place with number bigger than 1 represents a tree can be walked through, and this positive number represents the tree's height.
 

You are asked to cut off all the trees in this forest in the order of tree's height - always cut off the tree with lowest height first. And after cutting, the original place has the tree will become a grass (value 1).

You will start from the point (0, 0) and you should output the minimum steps you need to walk to cut off all the trees. If you can't cut off all the trees, output -1 in that situation.

You are guaranteed that no two trees have the same height and there is at least one tree needs to be cut off.

Example 1:

Input: 
[
 [1,2,3],
 [0,0,4],
 [7,6,5]
]
Output: 6
 

Example 2:

Input: 
[
 [1,2,3],
 [0,0,0],
 [7,6,5]
]
Output: -1
 

Example 3:

Input: 
[
 [2,3,4],
 [0,0,5],
 [8,7,6]
]
Output: 6
Explanation: You started from the point (0,0) and you can cut off the tree in (0,0) directly without walking.
 

Hint: size of the given matrix will not exceed 50x50.

Accepted
23,159

*/
class Solution {
private:
    bool check(int x, int y, int xSize, int ySize){
        if (x < 0 || y < 0 || x>= xSize || y >= ySize)
            return false;
        return true;
    }
public:
    int cutOffTree(vector<vector<int>>& forest) {
        /*
            1. Count number of trees
            2. 
        
        */
        if (forest.size() < 1) return 0;
        if (forest[0][0] == 0) return -1;
        priority_queue<int, vector<int>, greater<int>> pq;
        int trees = 0;
        for (auto f : forest){
            for (auto el : f)
                if (el > 1){
                    trees++;
                    pq.push(el);
                }                    
        }
        int i = 0;
        int j = 0;
        int steps = 0;
        vector<int> directions = {0,1,0,-1,0};
        while (!pq.empty()){            
            int target = pq.top();             
            // find target
            queue<pair<int, pair<int,int>>> q;
            q.push({i,{j, steps}});
            if (forest[i][j] == target){
                forest[i][j] = 1;
                q.pop();
                pq.pop();
            }else{
                vector<vector<bool>> visited(forest.size(), vector<bool>(forest[0].size(), 0));
                 
                
                while (!q.empty()){
                    bool find = false;
                    int n = q.size();                  
                    for (int t = 0; t < n; t++){
                        int X = q.front().first;
                        int Y = q.front().second.first;
                      //  cout << X << " - " << Y << "\n";
                        int currentSteps = q.front().second.second + 1;   
                        q.pop();
                        for (int d = 0; d < directions.size() - 1; d++){
                            int newX = X + directions[d];
                            int newY = Y + directions[d + 1];
                            if (check(newX, newY, forest.size(), forest[0].size()) && forest[newX][newY] != 0){
                                if (forest[newX][newY] == target){
                                    steps = currentSteps;
                                    find = true;
                                    i = newX;
                                    j = newY;
                                   // cout <<forest[newX][newY] << " " << steps << endl;
                                    forest[newX][newY] = 1;
                                    visited[newX][newY] = 1;
                                    pq.pop();
                                    break;
                                }
                                else {
                                  ///  cout <<forest[newX][newY] << " " << steps << endl;
                                    if (visited[newX][newY] != 1){
                                        q.push({newX,{newY, currentSteps}});                                    
                                        visited[newX][newY] = 1;   
                                    }                                    
                                }                                                                        
                            }
                        }
                        if (find)
                            break;
                    }
                    
                    if (q.empty() && !find)
                        return -1;
                    else 
                        if (find)
                            break;
                }
            }
        }
        
        return steps;
    }
};