/*
Given a set of points in the xy-plane, determine the minimum area of a rectangle formed from these points, with sides parallel to the x and y axes.

If there isn't any rectangle, return 0.

 

Example 1:

Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
Output: 4
Example 2:

Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
Output: 2
 

Note:

1 <= points.length <= 500
0 <= points[i][0] <= 40000
0 <= points[i][1] <= 40000
All points are distinct.
*/
class Solution {
public:
    
    int minAreaRect(vector<vector<int>>& points, int res = INT_MAX) {
        unordered_map<int, set<int>> x;
  for (auto p : points) x[p[0]].insert(p[1]);
  for (auto i = x.begin(); i != x.end(); ++i)
    for (auto j = next(i); j != x.end(); ++j) {
      if (i->second.size() < 2 || j->second.size() < 2) continue;
      vector<int> y;
      set_intersection(begin(i->second), end(i->second),
        begin(j->second), end(j->second), back_inserter(y));
      for (int k = 1; k < y.size(); ++k)
        res = min(res, abs(j->first - i->first) * (y[k] - y[k - 1]));
    }
  return res == INT_MAX ? 0 : res;
    }
};