/*
A rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) are the coordinates of its bottom-left corner, and (x2, y2) are the coordinates of its top-right corner.

Two rectangles overlap if the area of their intersection is positive.  To be clear, two rectangles that only touch at the corner or edges do not overlap.

Given two (axis-aligned) rectangles, return whether they overlap.

Example 1:

Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
Output: true
Example 2:

Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
Output: false
Notes:

Both rectangles rec1 and rec2 are lists of 4 integers.
All coordinates in rectangles will be between -10^9 and 10^9.
*/
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return (min(rec1[2], rec2[2]) > max(rec1[0], rec2[0]) && // width > 0
                min(rec1[3], rec2[3]) > max(rec1[1], rec2[1]));  // height > 0
        // return fieldIntersect(rec1[0],rec1[1],rec1[2],rec1[3],rec2[0],rec2[1],rec2[2],rec2[3]) > 0;
    }
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
