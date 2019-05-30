/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area

Example:

Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
Output: 45
Note:

Assume that the total area is never beyond the maximum possible value of int.
*/
class Solution {
public:
    
    long long fieldIntersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
            long left = std::max(x1, x3);
    long top = std::min(y2, y4);
    long right = std::min(x2, x4);
    long bottom = std::max(y1, y3);

    long width = right - left;
    long height = top - bottom;

    if ((width < 0) || (height < 0))
        return 0;
          
      return width * height;
    }
    int computeArea(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
     long long s = abs(x1-x2)*abs(y1-y2)- fieldIntersect(x1,y1,x2,y2,x3,y3,x4,y4) + abs(x3-x4)*abs(y3-y4) ;      
        return s;
    }
};